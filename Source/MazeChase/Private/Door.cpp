// Marcos Vázquez. ESAT 2017.

#include "MazeChase.h"
#include "Door.h"


ADoor::ADoor() {
	PrimaryActorTick.bCanEverTick = true;

	status_ = kClosed;
}


void ADoor::BeginPlay() {
	Super::BeginPlay();
	
}


void ADoor::Tick( float DeltaTime ) {
	Super::Tick( DeltaTime );

	FVector loc = GetActorLocation();

	switch (status_) {
	case kOpening:
		SetActorLocation(FVector(loc.X, loc.Y, loc.Z - 1));
		break;
	case kClosing:
		SetActorLocation(FVector(loc.X, loc.Y, loc.Z + 1));
		break;
	}
}


void ADoor::enable() {
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
}


void ADoor::disable() {
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
}


void ADoor::open(float time_to_stop, float time_to_close) {
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "OPENING");
	if (status_ == kClosed) {
		status_ = kOpening;
		
		//Clear timers
		GetWorld()->GetTimerManager().ClearTimer(door_stop_opening_handle_);
		GetWorld()->GetTimerManager().ClearTimer(door_close_handle_);
		GetWorld()->GetTimerManager().ClearTimer(door_stop_closing_handle_);

		//Set new timers
		GetWorld()->GetTimerManager().SetTimer(door_stop_opening_handle_, this, &ADoor::stop, time_to_stop, false);
		GetWorld()->GetTimerManager().SetTimer(door_close_handle_, this, &ADoor::close, time_to_close, false);
		GetWorld()->GetTimerManager().SetTimer(door_stop_closing_handle_, this, &ADoor::stop, time_to_stop + time_to_close, false);
	}
}


void ADoor::close() {
	if (status_ == kOpen) {
		status_ = kClosing;
	}
}


void ADoor::stop() {
	status_ = (status_ == kOpening) ? kOpen : kClosed;
}