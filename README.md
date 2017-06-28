# UE4-Plugin-SideBySide

1. If you don't have one, create a folder called "Plugin" in your project directory (where your content folder is located).
2. Checkout the project and copy the plugin to this folder
3. Right-click on your *.uproject  file and generate Visual Studio Project files.
4. Open Visual Studio and build plugin. 
5. Start Unreal Engine
6. Activate Plugin and restart.
7. In the file DefaultEngine.ini in your Config folder, look for the heading: "[/Script/Engine.Engine]"
8. In this section, add "GameEngine=/Script/SideBySidePlugin.StereoRendering.CustomGameEngine"
9. When you start your app next time in Standalone Mode, it should be side-by-side.

