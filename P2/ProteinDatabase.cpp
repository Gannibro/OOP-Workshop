#include "ProteinDatabase.h"
#include <fstream>
#include <utility>

namespace seneca {

ProteinDatabase::ProteinDatabase(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        std::string sequence;
        while (getline(file, line)) {
            if (line[0] == '>') {
                if (!sequence.empty()) {
                    sequences.push_back(sequence);
                    sequence.clear();
                }
            } else {
                sequence += line;
            }
        }
        if (!sequence.empty()) {
            sequences.push_back(sequence);
        }
    }
}

size_t ProteinDatabase::size() const {
    return sequences.size();
}

std::string ProteinDatabase::operator[](size_t index) const {
    if (index < sequences.size()) {
        return sequences[index];
    } else {
        return "";
    }
}

// Copy constructor
ProteinDatabase::ProteinDatabase(const ProteinDatabase& other)
    : sequences(other.sequences) {}

// Copy assignment operator
ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& other) {
    if (this != &other) {
        sequences = other.sequences;
    }
    return *this;
}

// Move constructor
ProteinDatabase::ProteinDatabase(ProteinDatabase&& other) noexcept
    : sequences(std::move(other.sequences)) {}

// Move assignment operator
ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& other) noexcept {
    if (this != &other) {
        sequences = std::move(other.sequences);
    }
    return *this;
}

} // namespace seneca
