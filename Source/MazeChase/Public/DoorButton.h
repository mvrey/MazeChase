// Marcos Vázquez. ESAT 2017.

#pragma once

#include "GameFramework/Actor.h"
#include "Door.h"
#include "DoorButton.generated.h"

UCLASS()
class MAZECHASE_API ADoorButton : public AActor
{
	GENERATED_BODY()
	
public:	
	ADoorButton();
	virtual void BeginPlay() override;
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintCallable, category = "methods")
	void openDoors();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
		TArray<ADoor*> linked_doors_;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Config")
		float time_opening_;
};
