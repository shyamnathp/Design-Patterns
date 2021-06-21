//
// Created by shyamnath on 6/6/21.
//
#include <memory>

class Database{
public:
    static Database& getInstance()
    {
        if (database== nullptr)
            database = std::unique_ptr<Database>(new Database);

        return *database;
    }

    Database(const Database&) = delete;
    Database(Database&&) = delete;
    Database& operator=(const Database&)=delete;
    Database& operator=(Database&&)=delete;
private:
    Database() = default;
    static std::unique_ptr<Database> database;
};

