#include <string>

class Level
{
public:
  Level();
  ~Level() {}

  void update();
  void render();
  void loadMap(const char* name);
  void loadTiles();
  void drawMap();
  void setMap();

private:
  std::vector<Tileset> m_tilesets;
  std::vector<Layer*> m_layers;
  Map gameMap;
  Tileset tileSet[100];
};

struct Tileset : public Entity
{
  int firstGridID;
  int tileWidth;
  int tileHeight;
  int spacing;
  int margin;
  int width;
  int height;
  int numColumns;
  std::string name;
};

struct Map
{
  Vector2f startPos = Vector2f(0, 0);
  Vector2f maxPos = Vector2f(0, 0);

  std::vector<int, vector<int>> tile(mapPos.getX(), vector<int>(mapPos.getY()));
}
