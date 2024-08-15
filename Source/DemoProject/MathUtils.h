#pragma once

class MathUtils
{
public:
	static float GetDistance(float Accelerate, float V, float Time)
	{
		return V * Time + 1.0f / 2.0f * Accelerate * FMath::Pow(Time, 2);
	}

	static float GetDeltaX(float V, float V0, float DeltaTime)
	{
		return (V + V0) * DeltaTime / 2.0f;
	}

	static float GetV0(float V, float Accelerate, float DeltaTime)
	{
		return V + Accelerate * DeltaTime;
	}
};
