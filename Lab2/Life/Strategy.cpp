#include "Strategy.h"

namespace Life{

void Strategy::exec(){

}

ExitStrategy::ExitStrategy(){}

void ExitStrategy::exec(){
  exit(0);
}

NextTikStrategy::NextTikStrategy(std::shared_ptr<Field> f) : fd(f){}

void NextTikStrategy::exec(){
  fd->processing();
}

NextTiksStrategy::NextTiksStrategy(std::shared_ptr<Field> f, unsigned int k) :  fd(f), num(k){}

void NextTiksStrategy::exec(){
  for(unsigned int itr = 0; itr < num; itr++){
      fd->processing();
    }
}

UploadFieldStrategy::UploadFieldStrategy(std::shared_ptr<Field> f, std::string s) :  fd(f), path(s){}

void UploadFieldStrategy::exec(){
  FieldLoader loader;
  *(this->fd) = loader.load(this->path);
}

SaveFieldStrategy::SaveFieldStrategy(std::shared_ptr<Field> f, std::string s): fd(f), path(s){}

void SaveFieldStrategy::exec(){
  FieldSaver saver;
  saver.save(this->path, *(fd.get()));
}

}
