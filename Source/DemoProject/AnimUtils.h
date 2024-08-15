#pragma once

class AnimUtils
{
public:
	template<typename T>
	static T* FindNotifyByClass(UAnimSequenceBase* Animation)
	{
		if(!Animation) return nullptr;

		const auto NotifyEvents = Animation->Notifies;
		for(auto NotifyEvent:NotifyEvents)
		{
			auto AnimNotify = Cast<T>(NotifyEvent.Notify);
			if(AnimNotify) return AnimNotify;
		}

		return nullptr;
	}

	template<typename T>
	static TArray<T*> FindNotifiesByClass(UAnimSequenceBase* Animation)
	{
		TArray<T*> Ret;
		const auto NotifyEvents = Animation->Notifies;
		for(auto NotifyEvent:NotifyEvents)
		{
			auto AnimNotify = Cast<T>(NotifyEvent.Notify);
			if(AnimNotify)
			{
				Ret.Add(AnimNotify);
			}
		}

		return Ret;
	}

	template<typename T>
	static TArray<T*> FindNotifyStatesByClass(UAnimSequenceBase* Animation)
	{
		TArray<T*> Ret;
		const auto NotifyEvents = Animation->Notifies;
		for(auto NotifyEvent:NotifyEvents)
		{
			auto AnimNotify = Cast<T>(NotifyEvent.NotifyStateClass);
			if(AnimNotify)
			{
				Ret.Add(AnimNotify);
			}
		}
		return Ret;
	}
};