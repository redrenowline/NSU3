#include "FieldLoader.h"

namespace Life{

bool FieldLoader::checkIdentity(std::ifstream &fl) {
  std::string tmp_s;
  std::getline(fl, tmp_s);
  if (tmp_s != INDICATOR)
    throw std::exception();
  return true;
}

std::string FieldLoader::readTitle(std::ifstream& fl) {
  std::string tmp_s;
  std::getline(fl, tmp_s);
  int pos;
  if (tmp_s.size() == 0)
    throw std::exception();
  pos = tmp_s.find(NAMEINDICATOR);
  if (pos == -1)
    throw std::exception();
  tmp_s.erase(pos, 2);
  while (tmp_s[0] == ' ') {
    tmp_s.erase(0, 1);
    if (tmp_s.size() == 0)
      throw std::exception();
  }
  return tmp_s;
}

Specification FieldLoader::readRules(std::ifstream &fl) {
  std::string tmp_s, tmp_sub;
  int pos;
  Specification sp;
  std::getline(fl, tmp_s);
  pos = tmp_s.find(RULESINDICATOR);
  if (pos == -1)
    throw std::exception();
  tmp_s.erase(pos, 3);
  if (tmp_s.size() == 0)
    throw std::exception();
  while (tmp_s[0] == ' ') {
    tmp_s.erase(0, 1);
    if (tmp_s.size() == 0)
      throw std::exception();
  }
  pos = tmp_s.find(BIRTHINDICATOR);
  if (pos == -1)
    throw std::exception();
  tmp_s.erase(pos, 1);
  char t_num = tmp_s[0];
  std::vector<unsigned char> temp;
  while (t_num >= '0' && t_num <= '9' && tmp_s.size() != 0) {
    temp.push_back(t_num);
    tmp_s.erase(0,1);
    if (tmp_s.size() == 0)
      throw std::exception();
    t_num = tmp_s[0];
  }
  sp.setcrReason(temp);
  temp.clear();
  if (tmp_s.size() == 0 || tmp_s.find(SURVIVEINDICATOR) == -1)
    throw std::exception();
  tmp_s.erase(0, 2);
  if (tmp_s.size() == 0)
    throw std::exception();
  t_num = tmp_s[0];
  while (t_num >= '0' && t_num <= '9' && tmp_s.size() != 0) {
    temp.push_back(t_num);
    tmp_s.erase(0, 1);
    if (tmp_s.size() == 0){
        sp.setsrReason(temp);
      return sp;
    }
    t_num = tmp_s[0];
  }
  sp.setsrReason(temp);
  return sp;
}

Field FieldLoader::load(std::string path) {
  Specification t_sp;
  std::ifstream fl;
  fl.open(path);
  if (!fl.is_open())
    throw std::exception();

  checkIdentity(fl);
  std::string title = readTitle(fl);
  t_sp = readRules(fl);
  Field res(50,50, t_sp);
  res.title = title;
  while (!fl.eof()) {
    unsigned int x, y;
    fl >> x >> y;
    res.mass[x][y] = cType::ALIVE;
    std::cout << "I'm at " << x << " " << y << "\n";
  }
  fl.close();
  return res;
}
}
