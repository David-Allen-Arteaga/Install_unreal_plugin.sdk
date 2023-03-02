// Copyright © 2021++ Ready Player Me

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/IHttpRequest.h"

DECLARE_DELEGATE_OneParam(FFileDownloadCompleted, bool /*bSuccess*/);

class FReadyPlayerMeBaseRequest : public TSharedFromThis<FReadyPlayerMeBaseRequest>
{
public:
	void Download(const FString& Url, float Timeout = -1.f);

	void CancelRequest();

	FFileDownloadCompleted& GetCompleteCallback();

	const TArray<uint8>& GetContent() const;
	
	FString GetContentAsString() const;

	FString GetHeader(const FString& Header) const;

private:
	void OnReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bSuccess);

	FFileDownloadCompleted OnDownloadCompleted;

protected:
	TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> DownloadRequest;
};
