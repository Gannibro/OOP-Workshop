#ifndef SENECA_PROTEINDATABASE_H
#define SENECA_PROTEINDATABASE_H

#include <string>
#include <fstream>
#include <vector>

namespace seneca {

class ProteinDatabase {
    std::vector<std::string> sequences;

public:
    ProteinDatabase() = default;

    ProteinDatabase(const std::string& filename) {
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

    size_t size() const {
        return sequences.size();
    }

    std::string operator[](size_t index) const {
        if (index < sequences.size()) {
            return sequences[index];
        } else {
            return "";
        }
    }

    // Copy constructor
    ProteinDatabase(const ProteinDatabase& other)
        : sequences(other.sequences) {}

    // Copy assignment operator
    ProteinDatabase& operator=(const ProteinDatabase& other) {
        if (this != &other) {
            sequences = other.sequences;
        }
        return *this;
    }

    // Destructor
    ~ProteinDatabase() = default;
};

} // namespace seneca

#endif // SENECA_PROTEINDATABASE_H
