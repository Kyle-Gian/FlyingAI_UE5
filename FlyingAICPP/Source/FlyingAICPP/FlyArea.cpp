// Fill out your copyright notice in the Description page of Project Settings.


#include "FlyArea.h"

// Sets default values
AFlyArea::AFlyArea()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AFlyArea::SetMinMaxExtents(TArray<FVector> a_corners)
{
	maxExtents = GetActorLocation() + (flyZoneScale / 2);
	a_corners.Add(maxExtents);
	minExtents = (flyZoneScale / 2) - GetActorLocation();
	a_corners.Add(minExtents);

}

void AFlyArea::GetSpacingBetweenNodes()
{
	nodeSpacing = flyZoneScale / nodesRequiredForEachAxis.operator-(1);
}

void AFlyArea::CreateNodesInFlyArea()
{
	while (nextNodePosition.X <= maxExtents.X)
	{
		US_PositionNode newPositionNode = US_PositionNode(nextNodePosition, true);
		nodeArray.Add(&newPositionNode);

		nextNodePosition.X += nodeSpacing.X;
	}

	nextNodePosition = FVector(minExtents.X, nextNodePosition.Y + nodeSpacing.Y, nextNodePosition.Z);

	if (nextNodePosition.Y <= maxExtents.Y)
		CreateNodesInFlyArea();


	nextNodePosition = FVector(minExtents.X, minExtents.Y, nextNodePosition.Z + nodeSpacing.Z);

	if (nextNodePosition.Z <= maxExtents.Z)
		CreateNodesInFlyArea();
}

void AFlyArea::CreateNavMesh()
{
	nodeArray.Empty();
	corners.Empty();

	SetMinMaxExtents(corners);
	GetSpacingBetweenNodes();

	nextNodePosition = minExtents;
	CreateNodesInFlyArea();

	for (auto node : nodeArray)
	{
		DrawDebugBox(GetWorld(), node->position, FVector(30.0f, 30.0f, 30.0f), FColor::Blue, true);
	}


}



// Called when the game starts or when spawned
void AFlyArea::BeginPlay()
{
	Super::BeginPlay();


}

void AFlyArea::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	nodeArray.Empty();
	corners.Empty();
	SetMinMaxExtents(corners);
	
	corners.Add(FVector(minExtents.X, maxExtents.Y, maxExtents.Z));
	corners.Add(FVector(maxExtents.X, minExtents.Y, maxExtents.Z));
	corners.Add(FVector(maxExtents.X, maxExtents.Y, minExtents.Z));
	corners.Add(FVector(maxExtents.X, minExtents.Y, minExtents.Z));
	corners.Add(FVector(minExtents.X, maxExtents.Y, minExtents.Z));
	corners.Add(FVector(minExtents.X, minExtents.Y, maxExtents.Z));

	for (auto corner : corners)
	{
		DrawDebugSphere(GetWorld(), corner, 10, 12, FColor::Red, false, 20);
	}



}
// Called every frame
void AFlyArea::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

