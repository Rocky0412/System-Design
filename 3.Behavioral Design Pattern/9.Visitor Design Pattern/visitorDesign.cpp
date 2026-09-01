#include <iostream>
#include <string>
#include <vector>

using namespace std;

class DocumentElement{
    
    public:
    string name;
    DocumentElement(string name){
        this->name=name;
    }

};
class TextFile:public DocumentElement{
    public:
    TextFile(string name):DocumentElement(name){};

};
class AudioFile:public DocumentElement{
    public:
    AudioFile(string name):DocumentElement(name){};
    
};
class videoFile:public DocumentElement{
    public:
    videoFile(string name):DocumentElement(name){};
    
};
class Ivisitor{
    public:
    virtual void visit(TextFile* text)=0;
    virtual void visit(videoFile* video)=0;
    virtual void visit(AudioFile* audio)=0;
};

class sizeVisitor: public Ivisitor{
    public:
    void visit( TextFile *text) override {
        cout<<"name:"<<text->name<<" size:text"<<endl;

    }
    void visit( videoFile *video) override {
        cout<<"name:"<<video->name<<" size:video"<<endl;

    }
    void visit(AudioFile* audio) override {
        cout<<"name:"<<audio->name<<" size:text"<<endl;

    }
};
class compressVisitor:public Ivisitor{
    public:
    void visit( TextFile *text) override {
        cout<<"name:"<<text->name<<" compress:text"<<endl;

    }
    void visit( videoFile *video) override {
        cout<<"name:"<<video->name<<" compress:video"<<endl;

    }
    void visit(AudioFile* audio) override {
        cout<<"name:"<<audio->name<<" compress:Audio"<<endl;

    }

};
int main()
{
    Ivisitor* sv= new sizeVisitor();
    Ivisitor* cv= new compressVisitor();
    TextFile* tf= new TextFile("file.txt");
    AudioFile* af= new AudioFile("file.mp4");
    videoFile* vf= new videoFile("file.720p");
    cout<<"\n"<<endl;
    cout<<"Size\n"<<endl;
    sv->visit(tf);
    sv->visit(af);
    sv->visit(vf);
    cout<<"\n"<<endl;
    cout<<"Compressed\n"<<endl;
    cv->visit(tf);
    cv->visit(af);
    cv->visit(vf);

    return 0;
}