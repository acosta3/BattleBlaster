// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"

#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/GameplayStatics.h"






ATank::ATank()
{
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringComp"));
	SpringArmComp->SetupAttachment(CapsuleComp);

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(SpringArmComp);
}

// Called when the game starts or when spawned

void ATank::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PlayerController= Cast<APlayerController>(Controller);

	if(PlayerController)
	{
		ULocalPlayer* LocalPlayer = PlayerController->GetLocalPlayer();
		if(LocalPlayer)
		{
			UEnhancedInputLocalPlayerSubsystem* Subsystem;
			Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

			if(Subsystem)
			{
				Subsystem->AddMappingContext(DefaultMapping,0);
			}
			
		}
	}

}


// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if(EIC)
	{
		EIC->BindAction(MoveAction,ETriggerEvent::Triggered,this,&ATank::MoveInput);
	}

}

void ATank::MoveInput(const FInputActionValue& Value)
{

	float InputValue = Value.Get<float>();
	FVector DeltaLocation = FVector(0.0f,0.0f,0.0f);
	DeltaLocation.X = Speed * InputValue * UGameplayStatics::GetWorldDeltaSeconds(GetWorld());
	AddActorLocalOffset(DeltaLocation, true);
}
