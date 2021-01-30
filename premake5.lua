workspace "Patator"
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Patator/vendor/GLFW/include"
IncludeDir["GLAD"] = "Patator/vendor/GLAD/include"
IncludeDir["ImGui"] = "Patator/vendor/imgui"
IncludeDir["glm"] = "Patator/vendor/glm"

include "Patator/vendor/GLFW"
include "Patator/vendor/GLAD"
include "Patator/vendor/imgui"

project "Patator"
    location "Patator"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
    

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "patpch.h"
    pchsource "Patator/src/patpch.cpp"

    defines
    {
        "_CRT_SECURE_NO_WARNINGS"
    }

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.GLAD}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}",
        "%{prj.name}/src"
    }

    links
    {
        "GLFW",
        "GLAD",
        "ImGui",
        "opengl32.lib"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "PAT_PLATFORM_WINDOWS",
            "GLFW_INCLUDE_NONE"
        }

    filter "configurations:Debug"
        defines "PAT_DEBUG"
        symbols "on"
        runtime "Debug"


    filter "configurations:Release"
        defines "PAT_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "PAT_DIST"
        runtime "Release"
        optimize "on"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Patator/vendor/spdlog/include",
        "Patator/vendor/GLFW/include",
        "Patator/vendor/GLAD/include",
        "%{IncludeDir.glm}",
        "Patator/src"
    }

    links
    {
        "Patator"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "PAT_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "PAT_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "PAT_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "PAT_DIST"
        runtime "Release"
        optimize "on"




