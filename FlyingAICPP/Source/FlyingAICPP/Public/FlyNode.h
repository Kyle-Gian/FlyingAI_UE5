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
	FVector worldLocation;
	UPROPERTY()
	bool isActive;
	UPROPERTY(VisibleAnywhere)
	FVector positionInGrid;

	TArray<FNodeEdge*> edges;
	
	FFlyNode()
	{
		worldLocation.Zero();
		isActive = true;
	}

	FFlyNode(FVector a_location, bool a_isActive)
	{
		worldLocation = a_location;
		isActive = a_isActive;
	}

	FFlyNode(FVector a_location, bool a_isActive, FVector a_posInArray)
	{
		worldLocation = a_location;
		isActive = a_isActive;
		positionInGrid = a_posInArray;
	}

	FORCEINLINE int GetNodePositionInArray(int a_width, int a_depth) const
	{
		//X+(S*Y)+((S*S)*Z)
		return positionInGrid.X + (a_width * positionInGrid.Y)  + ((a_depth * a_depth) * positionInGrid.Z);
	}
	
};
