#ifndef BLADES_COMBO_BLADE_H
#define BLADES_COMBO_BLADE_H
#include "blade_wrapper.h"

class ComboBladeWrapper;

class ComboBladeDummyStyle : public BladeStyle {
public:
  // Bladestyle implementation
  virtual void activate() override {
    if (real_style_)
      real_style_->activate();
  }
  virtual void deactivate() override {
    if (real_style_)
      real_style_->deactivate();
  }
  virtual void run(BladeBase* blade) override;

  bool IsHandled(HandledFeature effect) override {
    if (real_style_)
      return real_style_->IsHandled(effect);
    return false;
  }

  bool NoOnOff() override {
    if (real_style_)
      return real_style_->NoOnOff();
    return true;
  }

  void setRealStyle(BladeStyle* style){real_style_ = style;}

  BladeStyle* GetRealStyle(){return real_style_;}

  BladeStyle* UnSetRealStyle(){
    BladeStyle* result = real_style_;
    real_style_ = nullptr;
    return result;
  }

  ComboBladeDummyStyle(ComboBladeWrapper* comboBlade, BladeBase* primary_blade) :
    comboBlade_(comboBlade),
    primary_blade_(primary_blade),
    real_style_(nullptr){
  }
protected:
  ComboBladeWrapper* comboBlade_;
  BladeBase* primary_blade_;
  BladeStyle* real_style_;
};

class ComboBladeWrapper : public BladeWrapper {
public:
  ComboBladeWrapper(BladeBase* blade1, BladeBase* blade2):blade2_(blade2){
    blade_ = blade1;
    dummy_style_ = new ComboBladeDummyStyle(this, blade1);
    if (blade1)
      blade1->SetStyle(dummy_style_);
    if (blade2)
      blade2->SetStyle(dummy_style_);
  }

  int num_leds() const override {
    int result = 0;
    if (blade_) {
      result += blade_->num_leds();
    }
    if (blade2_) {
      result += blade2_->num_leds();
    }
    return result;
  }
  void set(int led, Color16 c) override {
    if (led < blade_->num_leds()) {
      if (blade_)
        return blade_->set(led, c);
    } else {
      if (blade2_ && blade_)
        return blade2_->set(led - blade_->num_leds(), c);
    }
  }
  void set_overdrive(int led, Color16 c) override {
    if (led < blade_->num_leds()) {
      if (blade_)
        return blade_->set_overdrive(led, c);
    } else {
      if (blade2_ && blade_)
        return blade2_->set_overdrive(led - blade_->num_leds(), c);
    }
  }

  void allow_disable() override {
    if (blade_)
      blade_->allow_disable();
    if (blade2_)
      blade2_->allow_disable();
  }

  void clear() override {
    if (blade_)
      blade_->clear();
    if (blade2_)
      blade2_->clear();
  }

  void Activate(int blade_number) override {
    if (blade_)
      blade_->Activate(blade_number);
    if (blade2_)
      blade2_->Activate(blade_number);
  }

  void Deactivate() override {
    if (blade_)
      blade_->Deactivate();
    if (blade2_)
      blade2_->Deactivate();
  }

  void SetStyle(BladeStyle* style) override {
    if (dummy_style_)
      dummy_style_->setRealStyle(style);
  }

  BladeStyle* UnSetStyle() override {
    if (dummy_style_)
      return dummy_style_->UnSetRealStyle();
    else
      return nullptr;
  }

  BladeStyle* current_style() const override {
    if (dummy_style_)
      return dummy_style_->GetRealStyle();
    else
      return dummy_style_;
  }

private:
  BladeBase* blade2_;
  ComboBladeDummyStyle* dummy_style_;
};

void ComboBladeDummyStyle::run(BladeBase* blade) {
  if (real_style_ && comboBlade_ && blade && blade == primary_blade_) {
    real_style_->run(static_cast<BladeBase*>(comboBlade_));
  }
}

BladeBase* ComboBlade(BladeBase* blade1, BladeBase* blade2)
{
  ComboBladeWrapper*result =  new ComboBladeWrapper(blade1, blade2);
  return result;
}
#endif
