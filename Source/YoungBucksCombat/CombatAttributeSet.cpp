#include "CombatAttributeSet.h"
#include "GameplayEffectExtension.h"

void UCombatAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    Super::PostGameplayEffectExecute(Data);

    // Example: make sure Health does not exceed MaxHealth or go below 0
    if (Health.GetCurrentValue() > MaxHealth.GetCurrentValue())
    {
        Health.SetCurrentValue(MaxHealth.GetCurrentValue());
    }
    else if (Health.GetCurrentValue() < 0.f)
    {
        Health.SetCurrentValue(0.f);
    }

    // Similar logic for Stamina if you want to clamp it
    if (Stamina.GetCurrentValue() > MaxStamina.GetCurrentValue())
    {
        Stamina.SetCurrentValue(MaxStamina.GetCurrentValue());
    }
    else if (Stamina.GetCurrentValue() < 0.f)
    {
        Stamina.SetCurrentValue(0.f);
    }
}
