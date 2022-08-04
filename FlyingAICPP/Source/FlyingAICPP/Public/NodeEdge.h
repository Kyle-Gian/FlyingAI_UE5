// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NodeEdge.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FNodeEdge
{
	GENERATED_BODY()

	UPROPERTY()
	FVector prevNodeNum;
	UPROPERTY()
	FVector nextNodeNum;
	
	FNodeEdge()
	{
		prevNodeNum = FVector::Zero();
		nextNodeNum = FVector::Zero();
	}
	FNodeEdge(FVector a_prevNodeNum, FVector a_nextNodeNum)
	{
		prevNodeNum = a_prevNodeNum;
		nextNodeNum = a_nextNodeNum;
	}

};