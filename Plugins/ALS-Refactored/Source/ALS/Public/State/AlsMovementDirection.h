﻿#pragma once

#include "AlsMovementDirection.generated.h"

UENUM(BlueprintType)
enum class EAlsMovementDirection : uint8
{
	Forward,
	Backward,
	Left,
	Right
};

USTRUCT(BlueprintType)
struct ALS_API FAlsMovementDirectionCache
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS", Meta = (AllowPrivateAccess))
	EAlsMovementDirection MovementDirection{EAlsMovementDirection::Forward};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS", Meta = (AllowPrivateAccess))
	bool bForward{true};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS", Meta = (AllowPrivateAccess))
	bool bBackward{false};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS", Meta = (AllowPrivateAccess))
	bool bLeft{false};

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ALS", Meta = (AllowPrivateAccess))
	bool bRight{false};

public:
	FAlsMovementDirectionCache() = default;

	FAlsMovementDirectionCache(const EAlsMovementDirection InitialMovementDirection)
	{
		*this = InitialMovementDirection;
	}

	bool IsForward() const
	{
		return bForward;
	}

	bool IsBackward() const
	{
		return bBackward;
	}

	bool IsLeft() const
	{
		return bLeft;
	}

	bool IsRight() const
	{
		return bRight;
	}

	operator EAlsMovementDirection() const
	{
		return MovementDirection;
	}

	void operator=(const EAlsMovementDirection NewMovementDirection)
	{
		MovementDirection = NewMovementDirection;

		bForward = MovementDirection == EAlsMovementDirection::Forward;
		bBackward = MovementDirection == EAlsMovementDirection::Backward;
		bLeft = MovementDirection == EAlsMovementDirection::Left;
		bRight = MovementDirection == EAlsMovementDirection::Right;
	}
};
