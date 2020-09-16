// Fill out your copyright notice in the Description page of Project Settings.


#include "LearningActorP01.h"

// Sets default values
ALearningActorP01::ALearningActorP01()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/**
	 * defaults
	*/
	total_damage = 20;
	total_damage_time = 1.0f;

}

void ALearningActorP01::PostInitProperties()
{
	Super::PostInitProperties();
	/**
	 * since dps is a transient property, it wont have a value unless
	 * we specifiy it in the PostInitProperties callback
	 *
	 * this callback is similar to React.componentDidMount
	*/
	CalculateDPS();
}

// Called when the game starts or when spawned
void ALearningActorP01::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ALearningActorP01::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALearningActorP01::CalculateDPS()
{
	damage_per_second = total_damage / total_damage_time;
}

void ALearningActorP01::CalledFromCppWithStub_Implementation()
{
	std::cout << "DEBUG: CalledFromCppWithStub_Implementation" << std::endl;
}

/**
 * this allows us to see damage_per_second calculated live in the
 * world editor
*/
#if WITH_EDITOR
void ALearningActorP01::PostEditChangeProperty(FPropertyChangedEvent &PropertyChangedEvent)
{
	CalculateDPS();

	Super::PostEditChangeProperty(PropertyChangedEvent);
}
#endif
