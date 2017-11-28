# UE4-Plugin-SideBySide

If you have a blueprint project continue with step 1.
If you have a Cpp project, continue with step 5.

##Convert BP to C++ project
1. Open your Blueprint project in UE4
2. File > New C++ Class > Add empty class
3. Visual Studio should open. You now have a BP/C++ Project.
4. Close Unreal Editor

##
5. If you don't have one, create a folder called "Plugin" in your project directory (where your content folder is located).
6. Checkout the project and copy the plugin to this folder
7. Right-click on your *.uproject  file and generate Visual Studio Project files.
8. Open Visual Studio and build plugin. 

9. Confirm that there _is no_ plugin folder.
10. Go to your uproject file
11. Right-click -> Generate Visual Studio Project Files
12. Reload solution in Visual Studio
13. Confirm that there _is_ a plugin folder.
14. Open the file [projectname].Build.cs (not the one in the plugin folder.)

15. Add the line "SideBySidePlugin" to the private modules or add the line:
	PrivateDependencyModuleNames.AddRange(new string[] { "SideBySidePlugin" });
16. Save
17. Rebuild your project/game
18. Start your project in Visual Studio via "Launch via Local Debugger".
19. If you get asked to build some modules, do it.
20. Close Unreal Editor.
21. You can now open the game via the Launcher or the uproject file.

22. In the file DefaultEngine.ini in the Config folder of your project, look for the heading: "[/Script/Engine.Engine]"
23. In this section, add "GameEngine=/Script/SideBySidePlugin.StereoRendering.CustomGameEngine" (without quotes)

When you start your app next time in Standalone Mode, it should be side-by-side.

Packaging your game should work as well.

28. November 2017: Tested on 4.18.1 with FirstPerson Blueprint template.


