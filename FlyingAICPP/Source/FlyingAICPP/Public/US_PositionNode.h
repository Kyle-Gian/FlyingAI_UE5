// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "US_PositionNode.generated.h"

/**
 * 
 */
UCLASS()
class FLYINGAICPP_API US_PositionNode : public UUserDefinedStruct
{
	GENERATED_BODY()
public:
	US_PositionNode();
	US_PositionNode(FVector a_position, bool a_isActive);
	~US_PositionNode();


	FVector position;
	bool isActive;
};
