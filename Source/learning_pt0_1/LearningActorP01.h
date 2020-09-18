// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LearningActorP01.generated.h"

UCLASS()
class LEARNING_PT0_1_API ALearningActorP01 : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALearningActorP01();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/**
	 * render this function callable from inside a Blueprint
	*/
	UFUNCTION(BlueprintCallable, Category="Damage")
	void CalculateDPS();

	/**
	 * This provides the ability to call functions implemented
	 * within the blueprint, from _within_ the CPP
	 * The BlueprintImplementableEvent attr means the function
	 * can be not-implemented in the Blueprint, in that case
	 * the call to `CalledFromCpp` will behave as if `CalledFromCpp`
	 * is defined as follows:
	 * CalledFromCpp() {};
	 * If we want to create a function defined in the Blueprint, but
	 * give it a defualt implementation to guard aganist it not being
	 * defined in the Blueprint we have to use the
	 * BlueprintNativeEvent attr instead of BlueprintImplementableEvent attr,
	 * and then we must define the fallback method in the CPP as such:
	 * <Class>::<FunctionName>_Implementation() {...}
	 * If we use BlueprintNativeEvent and do not provide a fallback, then
	 * we are idiots -- dont do this (unsure why, UE tutorial says 'it will fail
	 * to link' but doesnt specify what 'it' is, the tutorial claims that if
	 * the Blueprint doesnt implement the method we still get the null definition
	 * CalleFromCpp {}... moral of the story, dont use BlueprintNative if you dont
	 * plan on stubbing the method as described)
	 *
	 * It seems like the only purpose for this, is so that people who don't want to
	 * write explicit C++ have a way to build functionality
	 *
	 * AKA useless
	*/
	UFUNCTION(BlueprintImplementableEvent, Category="Damage")
	int CalledFromCpp();

	UFUNCTION(BlueprintNativeEvent, Category="Damage")
	int CalledFromCppWithStub();
	int CalledFromCppWithStub_Implementation();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void PostInitProperties() override;
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent &PropertyChangedEvent) override;
#endif

	/**
	 * UPROPERTY is a macro that allows us to take a attribute of an
	 * object, and specify where it is editable from
	 * In this case we've set it to `EditAnywhere`, which means we can
	 * edit it in code, or when placing an object of type ALearningActorP01
	 * in the world-editor, we can go to the objects details > damage to
	 * give it a value
	 * BlueprintReadWrite means we can edit this objects total_damage from
	 * Blueprints
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage")
	uint8 total_damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage")
	float total_damage_time;

	/**
	 * Transient -> non-persistent value, not saved to disk, calculated on the fly
	 * 	'derived'
	*/
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Transient, Category="Damage")
	float damage_per_second;

};
