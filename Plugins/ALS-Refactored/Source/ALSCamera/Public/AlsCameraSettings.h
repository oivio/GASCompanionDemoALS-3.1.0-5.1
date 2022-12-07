﻿#pragma once

#include "Engine/DataAsset.h"
#include "Engine/EngineTypes.h"
#include "Engine/Scene.h"
#include "Utility/AlsConstants.h"
#include "AlsCameraSettings.generated.h"

USTRUCT(BlueprintType)
struct ALSCAMERA_API FAlsFirstPersonCameraSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS", Meta = (ClampMin = 5, ClampMax = 360, ForceUnits = "deg"))
	float Fov{90.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS")
	FName CameraSocketName{TEXT("FirstPersonCamera")};
};

USTRUCT(BlueprintType)
struct ALSCAMERA_API FAlsTraceDistanceSmoothingSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS", Meta = (ClampMin = 0))
	float InterpolationSpeed{3.0f};
};

USTRUCT(BlueprintType)
struct ALSCAMERA_API FAlsThirdPersonCameraSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS", Meta = (ClampMin = 5, ClampMax = 360, ForceUnits = "deg"))
	float Fov{90.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS")
	FName FirstPivotSocketName{UAlsConstants::RootBone()};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS")
	FName SecondPivotSocketName{UAlsConstants::HeadBone()};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS", Meta = (ClampMin = 0, ForceUnits = "cm"))
	float TraceRadius{15.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS")
	TEnumAsByte<ETraceTypeQuery> TraceChannel{UEngineTypes::ConvertToTraceType(ECC_Visibility)};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS")
	FName TraceShoulderLeftSocketName{TEXT("ThirdPersonTraceShoulderLeft")};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS")
	FName TraceShoulderRightSocketName{TEXT("ThirdPersonTraceShoulderRight")};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS")
	FVector TraceOverrideOffset{0.0f, 0.0f, 40.0f};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS", Meta = (InlineEditConditionToggle))
	bool bUseTraceDistanceSmoothing{true};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS",
		DisplayName = "Use Trace Distance Smoothing", Meta = (EditCondition = "bUseTraceDistanceSmoothing"))
	FAlsTraceDistanceSmoothingSettings TraceDistanceSmoothing;
};

USTRUCT(BlueprintType)
struct ALSCAMERA_API FAlsCameraLagSubsteppingSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS", Meta = (ClampMin = 0.005, ClampMax = 0.5, ForceUnits = "s"))
	float LagSubstepDeltaTime{1.0f / 60.0f};
};

UCLASS(Blueprintable, BlueprintType)
class ALSCAMERA_API UAlsCameraSettings : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	bool bIgnoreTimeDilation{true};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	FAlsFirstPersonCameraSettings FirstPerson;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	FAlsThirdPersonCameraSettings ThirdPerson;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings", Meta = (InlineEditConditionToggle))
	bool bUseLagSubstepping;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings", DisplayName = "Use Lag Substepping",
		Meta = (EditCondition = "bUseLagSubstepping"))
	FAlsCameraLagSubsteppingSettings CameraLagSubstepping;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	FPostProcessSettings PostProcess;

#if WITH_EDITORONLY_DATA
public:
	virtual void Serialize(FArchive& Archive) override;
#endif
};
