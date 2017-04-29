// Marcos Vázquez. ESAT 2017.

#pragma once

#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class MAZECHASE_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	ADoor();

	virtual void BeginPlay() override;
	
	virtual void Tick( float DeltaSeconds ) override;

	void enable();
	void disable();

	UFUNCTION(BlueprintCallable, Category = "PassiveMethods")
	void open(float time_to_stop, float time_to_close);
	UFUNCTION(BlueprintCallable, Category = "PassiveMethods")
	void close();
	UFUNCTION(BlueprintCallable, Category = "PassiveMethods")
	void stop();


private:
	FTimerHandle door_stop_opening_handle_;
	FTimerHandle door_close_handle_;
	FTimerHandle door_stop_closing_handle_;

	typedef enum {
		kOpening,
		kClosing,
		kOpen,
		kClosed
	} DoorStatus;

	DoorStatus status_;
};
