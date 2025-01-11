#include "AbilityCharacter.h"

// Sets default values
AAbilityCharacter::AAbilityCharacter()
{
    // Set this character to call Tick() every frame.
    PrimaryActorTick.bCanEverTick = true;

    // Create an instance of the AbilitySystemComponent
    AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));

    // Create the AttributeSet subobject
    // By default, you might not want to replicate attribute sets that are only used locally.
    // If you do want to replicate them, set up their replication conditions.
    CombatAttributes = CreateDefaultSubobject<UCombatAttributeSet>(TEXT("CombatAttributeSet"));
}

void AAbilityCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void AAbilityCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AAbilityCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}

// Implement IAbilitySystemInterface
UAbilitySystemComponent* AAbilityCharacter::GetAbilitySystemComponent() const
{
    return AbilitySystemComponent;
}
