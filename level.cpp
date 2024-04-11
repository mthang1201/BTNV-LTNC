#include <fstream>
#include <vector>
#include <SDL.h>
#include

class Level
{
public:
  Level();
  ~Level() {}

  void update();
  void render();
  void loadMap(const char *name);
  void loadTiles();
  void drawMap();
  void setMap();

private:
  std::vector<Tileset> m_tilesets;
  std::vector<Layer *> m_layers;
};

void Level::loadMap(const char *name)
{
  FILE *fp = nullptr;
  fp = fopen(name, "r");
  if (fp == nullptr)
  {
    std::cout << "error";
  }

  for (int i = 0; i < gameMap.maxPos.getY(); i++)
  {
    for (int j = 0; j < gameMap.maxPos.getX(); j++)
    {
      fscanf(fp, "%d", &gameMap.tile[i][j]);
      int val = gameMap.tile[i][j];
      if (val > 0 && val < 100)
      {
        if (j > gameMap.maxPos.getX())
        {
          gameMap.maxPos.getX() = j;
        }

        if (i > gameMap.maxPos.getY())
        {
          gameMap.maxPos.getY() = i;
        }
      }
    }
  }

  gameMap.maxPos.setX((gameMap.maxPos.getX() + 1) * TILE_SIZE);
  gameMap.maxPos.setY((gameMap.maxPos.getY() + 1) * TILE_SIZE);


  fclose(fp);
}


void Level::loadTiles()
{
  char file_img[15];
  FILE *FP = nullptr;

  for (int i = 0; i < MAX_TILE; i++)
  {
    snprintf(file_img, sizeof(file_img), "res/%d.png", i);

    fp = fopen(file_img, "r");
    if (fp == nullptr)
    {
      continue;
    }
    fclose(fp);

    tileSet[i].loadImg(file_img, TheResourceManager::Instance()->getRenderer());
  }
}

void Level::drawMap()
{
  Vector2f map;
  int x1
  int x2

  int y1
  int y2

  for (int i = y1; i < y2; i+= TILE_SIZE)
  {
    Vector2f map.setX(gameMap.startPos.getX() / TILE_SIZE);
    for (int j = x1; j < x2; j += TILE_SIZE)
    {
      int val = gameMap.tile[map.getY()][map.getX()];
      if (val > 0 && val < MAX_TILE)
      {
        tileSet[val].setCurrentFrame(j, i);
        TheResourceManager::Instance()->drawTile(tileSet);
      }
      map.setX(map.getX() + 1);
    }
    map.setY(map.getY() + 1);
  }
}
