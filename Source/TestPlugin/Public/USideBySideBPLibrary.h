#pragma once
#include "Engine.h"
#include "USideBySideBPLibrary.generated.h"

/*
*	Function library class.
*	Each function in it is expected to be static and represents blueprint node that can be called in any blueprint.
*
*	When declaring function you can define metadata for the node. Key function specifiers will be BlueprintPure and BlueprintCallable.
*	BlueprintPure - means the function does not affect the owning object in any way and thus creates a node without Exec pins.
*	BlueprintCallable - makes a function which can be executed in Blueprints - Thus it has Exec pins.
*	DisplayName - full name of the node, shown when you mouse over the node and in the blueprint drop down menu.
*				Its lets you name the node using characters not allowed in C++ function names.
*	CompactNodeTitle - the word(s) that appear on the node.
*	Keywords -	the list of keywords that helps you to find node when you search for it using Blueprint drop-down menu.
*				Good example is "Print String" node which you can find also by using keyword "log".
*	Category -	the category your node will be under in the Blueprint drop-down menu.
*
*	For more info on custom blueprint nodes visit documentation:
*	https://wiki.unrealengine.com/Custom_Blueprint_Node_Creation
*/
UCLASS()
class USideBySideBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintPure, Category = "Output|Side-by-Side", meta = (DisplayName = "Test", Keywords = "Tests"))
	static bool Test();

	//////////////////////////////////////////////////////////////////////////
	//Eye offset
	UFUNCTION(BlueprintCallable, Category = "Output|Side-by-Side", meta = (DisplayName = "SetEyeOffset with delta", Keywords = "Set Eye Offset Delta"))
		static void SetEyeOffsetWithDelta(float _deltaOffset); //Sets the current IPD x 0.5 using a delta

	UFUNCTION(BlueprintCallable, Category = "Output|Side-by-Side", meta = (DisplayName = "GetEyeOffset", Keywords = "Get Eye Offset"))
		static float GetEyeOffset(); //Returns the current IPD x 0.5

	UFUNCTION(BlueprintCallable, Category = "Output|Side-by-Side", meta = (DisplayName = "SetEyeOffset", Keywords = "Get Eye Offset Delta"))
		static void SetEyeOffset(float _newEyeOffset); //Updates the current IPD x 0.5

	//////////////////////////////////////////////////////////////////////////
	//Projection offset
	UFUNCTION(BlueprintCallable, Category = "Output|Side-by-Side", meta = (DisplayName = "SetProjectionPlaneOffset with delta", Keywords = "Set Projection Plane Offset Delta"))
		static void SetProjectionPlaneOffsetWithDelta(float _deltaProjectonPlaneOffset); //Sets the current projection center offset using a delta

	UFUNCTION(BlueprintCallable, Category = "Output|Side-by-Side", meta = (DisplayName = "GetProjectionPlaneOffset", Keywords = "Get Projection Plane Offset"))
		static float GetProjectionPlaneOffset(); //returns the current projection center offset 

	UFUNCTION(BlueprintCallable, Category = "Output|Side-by-Side", meta = (DisplayName = "SetProjectionPlaneOffset", Keywords = "Set Projection Plane Offset"))
		static void SetProjectionPlaneOffset(float _newProjectionPLaneOffset); //Updates the current projection center offset 

	UFUNCTION(BlueprintCallable, Category = "Output|Side-by-Side", meta = (DisplayName = "SetShowDebugMessage", Keywords = "Show Debug Message"))
		static void SetShowDebugMessage(bool _newVal);

	//////////////////////////////////////////////////////////////////////////
	//FOV
	UFUNCTION(BlueprintCallable, Category = "Output|Side-by-Side", meta = (DisplayName = "Increment FOV", Keywords = "Increment FOV"))
		static void IncFOV(float _FOVOffset); 

	UFUNCTION(BlueprintCallable, Category = "Output|Side-by-Side", meta = (DisplayName = "Decrement FOV", Keywords = "Decrement FOV"))
		static void DecFOV(float _FOVOffset); 

	UFUNCTION(BlueprintCallable, Category = "Output|Side-by-Side", meta = (DisplayName = "Get FOV", Keywords = "Get FOV"))
		static float GetFOV();

	UFUNCTION(BlueprintCallable, Category = "Output|Side-by-Side", meta = (DisplayName = "Set FOV", Keywords = "Set FOV"))
		static void SetNewFOV(float _newFOV); //careful, there's also another SetFOV() class of StereoRenderingDevice.

	//////////////////////////////////////////////////////////////////////////
	//Stereo mode
	UFUNCTION(BlueprintCallable, Category = "Output|Side-by-Side", meta = (DisplayName = "Enable Stereo", Keywords = "Enable Stereo 3D"))
		static void EnableStereo(bool _stereo);

	UFUNCTION(BlueprintCallable, Category = "Output|Side-by-Side", meta = (DisplayName = "Is Stereo Enabled", Keywords = "Is Enabled Stereo 3D"))
		static bool IsStereoEnabled();
};