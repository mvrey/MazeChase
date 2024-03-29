// Marcos Vázquez. ESAT 2017.

#include "MazeChase.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "Minotaur.h"
#include "BTTask_UpdateSensoryInfo.h"


EBTNodeResult::Type UBTTask_UpdateSensoryInfo::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {

	//return EBTNodeResult::InProgress;

	AAIController* MyController = OwnerComp.GetAIOwner();

	if (!MyController)
		return EBTNodeResult::Failed;

	UBlackboardComponent* BBComp = OwnerComp.GetBlackboardComponent();
	if (!BBComp)
		return EBTNodeResult::Failed;

	AMinotaur* myChar = Cast<AMinotaur>(MyController->GetControlledPawn());


	BBComp->SetValueAsObject("PlayerRef", myChar->player_ref_);

	return EBTNodeResult::Succeeded;

}