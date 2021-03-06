#pragma once

#include "HTNPlanner/PrimitiveTask.h"
#include "HTNTask_ExploreSimpleFPS.generated.h"

struct FHTNTask_ExploreSimpleFPSMemory
{
	int32 Area;
};

/**
 * 'Explore' primitive task for the SimpleFPS domain.
 */
UCLASS()
class HTN_PLUGIN_API UHTNTask_ExploreSimpleFPS : public UPrimitiveTask
{
	GENERATED_BODY()

public:
	UHTNTask_ExploreSimpleFPS(const FObjectInitializer& ObjectInitializer);

	virtual void ApplyTo(TSharedPtr<FHTNWorldState> WorldState, uint8* TaskMemory) const override;
	virtual EHTNExecutionResult ExecuteTask(UHTNPlannerComponent& HTNComp, uint8* TaskMemory) override;
	virtual float GetCost(const TSharedPtr<FHTNWorldState> WorldState, uint8* TaskMemory) const override;
	virtual uint16 GetInstanceMemorySize() const override;
	virtual bool IsApplicable(const TSharedPtr<FHTNWorldState> WorldState, uint8* TaskMemory) const override;

	virtual FString GetTaskName(uint8* TaskMemory) const override;

protected:
	/**
	 * Caching the heuristic cost here. Only the class CDO needs to memorize this,
	 * so it doesn't go into the TaskMemory of individual instances of this class.
	 */
	float HeuristicCost;
};