// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FlyNode.generated.h"

struct FNodeEdge;
/**
 * 
 */
USTRUCT(BlueprintType)
struct FFlyNode
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	FVector location;
	UPROPERTY()
	bool isActive;
	UPROPERTY(VisibleAnywhere)
	FVector positionInArray;

	TArray<FNodeEdge*> edges;
	
	FFlyNode()
	{
		location.Zero();
		isActive = true;
	}

	FFlyNode(FVector a_location, bool a_isActive)
	{
		location = a_location;
		isActive = a_isActive;
	}

	FFlyNode(FVector a_location, bool a_isActive, FVector a_posInArray)
	{
		location = a_location;
		isActive = a_isActive;
		positionInArray = a_posInArray;
	}

	FORCEINLINE int GetNodePositionInArray() const
	{
		return (positionInArray.X + positionInArray.Y) * positionInArray.Z;
	}
	
};
