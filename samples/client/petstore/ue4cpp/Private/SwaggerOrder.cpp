/**
 * Swagger Petstore
 * This is a sample server Petstore server.  You can find out more about Swagger at [http://swagger.io](http://swagger.io) or on [irc.freenode.net, #swagger](http://swagger.io/irc/).  For this sample, you can use the api key `special-key` to test the authorization filters.
 *
 * OpenAPI spec version: 1.0.0
 * Contact: apiteam@swagger.io
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */
#include "SwaggerOrder.h"

#include "SwaggerModule.h"
#include "SwaggerHelpers.h"

#include "Templates/SharedPointer.h"

namespace Swagger 
{

inline FString ToString(const SwaggerOrder::StatusEnum& Value)
{
	switch (Value)
	{
	case SwaggerOrder::StatusEnum::Placed:
		return TEXT("placed");
	case SwaggerOrder::StatusEnum::Approved:
		return TEXT("approved");
	case SwaggerOrder::StatusEnum::Delivered:
		return TEXT("delivered");
	}

	UE_LOG(LogSwagger, Error, TEXT("Invalid SwaggerOrder::StatusEnum Value (%d)"), (int)Value);	
	return TEXT("");
}

inline FStringFormatArg ToStringFormatArg(const SwaggerOrder::StatusEnum& Value)
{
	return FStringFormatArg(ToString(Value));
}

inline void WriteJsonValue(JsonWriter& Writer, const SwaggerOrder::StatusEnum& Value)
{
	WriteJsonValue(Writer, ToString(Value));
}

inline bool TryGetJsonValue(const TSharedPtr<FJsonValue>& JsonValue, SwaggerOrder::StatusEnum& Value)
{
	FString TmpValue;
	if (JsonValue->TryGetString(TmpValue))
	{
		static TMap<FString, SwaggerOrder::StatusEnum> StringToEnum = {  };

		const auto Found = StringToEnum.Find(TmpValue);
		if(Found)
		{
			Value = *Found;
			return true;
		}
	}
	return false;
}

void SwaggerOrder::WriteJson(JsonWriter& Writer) const
{
	Writer->WriteObjectStart();
	if (Id.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("id")); WriteJsonValue(Writer, Id.GetValue());	
	}
	if (PetId.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("petId")); WriteJsonValue(Writer, PetId.GetValue());	
	}
	if (Quantity.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("quantity")); WriteJsonValue(Writer, Quantity.GetValue());	
	}
	if (ShipDate.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("shipDate")); WriteJsonValue(Writer, ShipDate.GetValue());	
	}
	if (Status.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("status")); WriteJsonValue(Writer, Status.GetValue());	
	}
	if (Complete.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("complete")); WriteJsonValue(Writer, Complete.GetValue());	
	}
	Writer->WriteObjectEnd();
}

bool SwaggerOrder::FromJson(const TSharedPtr<FJsonObject>& JsonObject)
{
	bool ParseSuccess = true;

	ParseSuccess &= TryGetJsonValue(JsonObject, TEXT("id"), Id);
	ParseSuccess &= TryGetJsonValue(JsonObject, TEXT("petId"), PetId);
	ParseSuccess &= TryGetJsonValue(JsonObject, TEXT("quantity"), Quantity);
	ParseSuccess &= TryGetJsonValue(JsonObject, TEXT("shipDate"), ShipDate);
	ParseSuccess &= TryGetJsonValue(JsonObject, TEXT("status"), Status);
	ParseSuccess &= TryGetJsonValue(JsonObject, TEXT("complete"), Complete);

	return ParseSuccess;
}
}
