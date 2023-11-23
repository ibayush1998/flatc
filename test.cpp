#include <iostream>
#include <iomanip>
#include <flatbuffers/flatbuffers.h>
#include "example_generated.h"

int main() {
    // Create a FlatBuffers builder
    flatbuffers::FlatBufferBuilder builder;

    // Create a Person object
    auto name = builder.CreateString("John Doe");
    auto person = Example::CreatePerson(builder, 123, name);

    // Finish building the buffer
    builder.Finish(person);

    // Access the buffer data
    const uint8_t *buf = builder.GetBufferPointer();
    int size = builder.GetSize();

    // Print the buffer data (for demonstration purposes)
    std::cout << "Buffer Data:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(buf[i]) << " ";
    }
    std::cout << std::dec << "\n";

    // TODO: You can write the buffer data to a file or perform other actions as needed

    return 0;
}

