#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "CombatAttributeSet.h"
#include "AbilityCharacter.generated.h"

/**
 * AAbilityCharacter
 *
 * This is your character class that integrates with the Gameplay Ability System.
 * It implements IAbilitySystemInterface and contains an AbilitySystemComponent
 * and a pointer to your CombatAttributeSet.
 */
UCLASS()
class YOUNGBUCKSCOMBAT_API AAbilityCharacter : public ACharacter, public IAbilitySystemInterface
{
    GENERATED_BODY()

public:
    // Sets default values for this character's properties
    AAbilityCharacter();

    // Implement IAbilitySystemInterface
    virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
    // The Ability System Component belonging to this character
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities", meta = (AllowPrivateAccess = "true"))
    UAbilitySystemComponent* AbilitySystemComponent;

    // The set of attributes for this character
    UPROPERTY()
    UCombatAttributeSet* CombatAttributes;
};
