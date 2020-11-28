workspace "Patator"
    architecture "x64"

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

include "Patator/vendor/GLFW"

project "Patator"
    location "Patator"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{prj.name}/src"
    }

    links
    {
        "GLFW"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "PAT_PLATFORM_WINDOWS",
            "PATATOR_BUILD_DLL",
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "PAT_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "PAT_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "PAT_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

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
        "Patator/src"
    }

    links
    {
        "Patator"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "PAT_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "PAT_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "PAT_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "PAT_DIST"
        optimize "On"




