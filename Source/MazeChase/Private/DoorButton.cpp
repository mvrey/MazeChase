// Marcos Vázquez. ESAT 2017.

#include "MazeChase.h"
#include "DoorButton.h"


ADoorButton::ADoorButton() {
	time_opening_ = 2.0f;
}


void ADoorButton::BeginPlay() {
	Super::BeginPlay();
}


void ADoorButton::Tick( float DeltaTime ) {
	Super::Tick( DeltaTime );
}


void ADoorButton::openDoors() {
	for (int i = 0; i < linked_doors_.Num(); i++) {
		ADoor* door = linked_doors_[i];
		door->disable();
		FTimerHandle door_handle;
		GetWorld()->GetTimerManager().SetTimer(door_handle, door, &ADoor::enable, time_opening_, false);
	}
}