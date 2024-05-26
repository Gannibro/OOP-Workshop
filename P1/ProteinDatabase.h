#ifndef SENECA_PROTEINDATABASE_H
#define SENECA_PROTEINDATABASE_H

#include <string>
#include <vector>

namespace seneca {

class ProteinDatabase {
    std::vector<std::string> sequences;

public:
    ProteinDatabase() = default;
    ProteinDatabase(const std::string& filename);
    
    size_t size() const;
    std::string operator[](size_t index) const;

    // Copy constructor
    ProteinDatabase(const ProteinDatabase& other);

    // Copy assignment operator
    ProteinDatabase& operator=(const ProteinDatabase& other);

    // Destructor
    ~ProteinDatabase() = default;
};

} // namespace seneca

#endif // SENECA_PROTEINDATABASE_H