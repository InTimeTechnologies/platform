#include "PlatformImplementation.h"

// Dependencies | std
#include <string>
#include <filesystem>
#include <iostream>
#include <vector>

// cpp Properties
static std::filesystem::path dirInputDevices = "/dev/input/";

// cpp Functions
static std::vector<std::filesystem::path> listPathsInputDevices() {
    std::vector<std::filesystem::path> pathsToInputDevices{};
    for (const std::filesystem::path& pathEntry : dirInputDevices) {
        pathEntry.string().find("event)");
    }
}

namespace it {
    namespace platform {
        // class PlatformImplementation

        // Object | public

        // Constructor / Destructor
        PlatformImplementation::PlatformImplementation() : Platform() {

		}
		PlatformImplementation::~PlatformImplementation() {
			deinit();
		}

        // Functions (Platform)
        bool PlatformImplementation::init() {
            std::cout << "Initiating Linux PlatformImplementation" << std::endl;

        }
        void PlatformImplementation::deinit() {

        }
        void PlatformImplementation::update() {

        }
    }
}
