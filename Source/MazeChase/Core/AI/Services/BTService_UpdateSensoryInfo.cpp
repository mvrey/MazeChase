// Marcos Vázquez. ESAT 2017.

#include "MazeChase.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Minotaur.h"
#include "BTService_UpdateSensoryInfo.h"


void UBTService_UpdateSensoryInfo::TickNode(UBehaviorTreeComponent&OwnerComp, uint8* NodeMemory, float DeltaSeconds) {
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	AAIController* controller = OwnerComp.GetAIOwner();	
	UBlackboardComponent* BBComp = OwnerComp.GetBlackboardComponent();
	if (!BBComp)
		return;

	AMinotaur* minos = Cast<AMinotaur>(controller->GetControlledPawn());

	BBComp->SetValueAsObject("PlayerRef", minos->player_ref_);
}

/** initialize any asset related data */
void UBTService_UpdateSensoryInfo::InitializeFromAsset(UBehaviorTree& Asset) {

	Super::InitializeFromAsset(Asset);

	UBlackboardData* BBAsset = GetBlackboardAsset();
	if (BBAsset)
	{
		TargetObject.ResolveSelectedKey(*BBAsset);
	}
	else
	{
		UE_LOG(LogBehaviorTree, Warning, TEXT("Can't initialize task: %s, make sure that behavior tree specifies blackboard asset!"), *GetName());
	}
}