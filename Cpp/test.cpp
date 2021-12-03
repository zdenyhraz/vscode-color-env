#include <iostream>
#include <memory>
#include <atomic>
#include <vector>
#include <algorithm>
#include <string>
#include <string_view>

#define LOG_DEBUG(message) std::cout << message << std::endl; // macro

std::atomic<int64_t> kId = 0; // namespace, type, global variable, literal, comment

class Entity // type
{
public:
  enum EntityType
  {
    Player, // enum
    Enemy,
    Particle
  };

  struct Vec4
  {
    float x = 0.0f; // built-in type, member variables
    float y = 0.0f;
    float z = 0.0f;
    float w = 0.0f;

    const Vec4& operator+=(const Vec4& vec) // member function, argument
    {
      x += vec.x; // built-in operator
      y += vec.y;
      z += vec.z;
      w += vec.w;
      return *this;
    }
  };

  // member functions
  Entity(const std::string& name, const Vec4& position, EntityType type) : mId(GenerateId()), mName(name), mPosition(position), mType(type) {}

  void Move(const Vec4& position)
  {
    LOG_DEBUG("Moving entity " << mId << " by " << position.x << " " << position.y << " " << position.z);
    mPosition += position; // overloaded operator
  }

  // member function
  const std::string& GetName() const { return mName; }

protected:
  // static member functions
  static int64_t GenerateId() { return kId++; }

  // static member variables
  static constexpr int64_t kMaxCount = 1234;

  // member variables
  int64_t mId = static_cast<int64_t>(0.0f);
  std::string mName = "Entity";
  Vec4 mPosition;
  EntityType mType;
};

template <typename T> // template
T Square(T x)         // function, type, agrument
{
  return x * x;
}

int main()
try // try block
{
  Entity player("Player", {1.63, 2.45, 3.98, 4.12}, Entity::Player);
  player.Move({4, 3, 2, 1});

  std::vector<std::shared_ptr<Entity>> enemies;
  enemies.emplace_back(std::make_shared<Entity>("Enemy 1", Entity::Vec4{1, 2, 3, 4}, Entity::Enemy));
  enemies.emplace_back(std::make_shared<Entity>("Enemy 2", Entity::Vec4{1, 2, 3, 4}, Entity::Enemy));

  if (std::any_of(enemies.begin(), enemies.end(), [](const auto& enemy) { return enemy->GetName() != "Bad"; }))
    throw std::runtime_error("These enemies are bad"); // throw

  if (enemies.empty() || enemies.size() >= 100 && enemies.capacity() != 1000)
    throw std::runtime_error("No enemies to work with");

  for (const auto& enemy : enemies)
    enemy->Move(Entity::Vec4{-6.1f, 5.3f, 4.0f, -3.6f});
}
catch (const std::exception& e) // catch block
{
  LOG_DEBUG("Error: " << e.what()); // macro
}