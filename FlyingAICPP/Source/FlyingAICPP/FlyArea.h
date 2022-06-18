// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "US_PositionNode.h"
#include "FlyArea.generated.h"

UCLASS()
class FLYINGAICPP_API AFlyArea : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFlyArea();
	void SetMinMaxExtents(TArray<FVector> a_corners);
	void GetSpacingBetweenNodes();
	void CreateNodesInFlyArea();
	void CreateNavMesh();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	TArray<FVector> corners;
	TArray<FVector> modeSpacing;
	TArray<FVector> mextNodePosition;
	UPROPERTY(EditAnywhere, Category= "Fly Area")
	TArray<US_PositionNode*> nodeArray;

	UPROPERTY(EditAnywhere, Category= "Fly Area")
	FVector nodesRequiredForEachAxis;

	UPROPERTY(EditAnywhere, Category= "Fly Area")
	FVector maxExtents;
	UPROPERTY(EditAnywhere, Category= "Fly Area")
	FVector minExtents;
	UPROPERTY(EditAnywhere, Category= "Fly Area")
	FVector flyZoneScale;
	FVector nodeSpacing;
	FVector nextNodePosition;
};
