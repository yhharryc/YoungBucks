#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "CombatAttributeSet.generated.h"

/**
 * UCombatAttributeSet
 *
 * This class defines your character attributes (Health, Stamina, Damage, etc.).
 * It inherits from UAttributeSet, which is the base class for the Gameplay Ability SystemÅfs attribute sets.
 */

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class YOUNGBUCKSCOMBAT_API UCombatAttributeSet : public UAttributeSet
{
    GENERATED_BODY()

public:
    // ----- Health -----
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
    FGameplayAttributeData Health;
    ATTRIBUTE_ACCESSORS(UCombatAttributeSet, Health)

        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
    FGameplayAttributeData MaxHealth;
    ATTRIBUTE_ACCESSORS(UCombatAttributeSet, MaxHealth)

        // ----- Stamina -----
        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
    FGameplayAttributeData Stamina;
    ATTRIBUTE_ACCESSORS(UCombatAttributeSet, Stamina)

        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
    FGameplayAttributeData MaxStamina;
    ATTRIBUTE_ACCESSORS(UCombatAttributeSet, MaxStamina)

        // ----- Damage -----
        UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
    FGameplayAttributeData Damage;
    ATTRIBUTE_ACCESSORS(UCombatAttributeSet, Damage)

        // Optionally, override this to clamp or respond to attribute changes
        virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
};
