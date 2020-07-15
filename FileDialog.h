#ifndef FileDialog_H
#define FileDialog_H

#include <QFileDialog>
#include <string>

class FileDialog : public QFileDialog{

	Q_OBJECT

public:
	FileDialog();
	~FileDialog();

};

#endif // !FileDialog_H
