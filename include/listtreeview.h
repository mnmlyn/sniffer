// =====================================================================================
// 
//       Filename:  listtreeview.h
//
//    Description:  主窗口数据捕获控件的类声明头文件
//
//        Version:  1.0
//        Created:  2013年01月22日 14时50分49秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  Hurley (LiuHuan), liuhuan1992@gmail.com
//        Company:  Class 1107 of Computer Science and Technology
// 
// =====================================================================================

#ifndef LISTTREEVIEW_H_
#define LISTTREEVIEW_H_

#include <QTreeView>

class QStandardItemModel;
class QModelIndex;
class QString;

class ListTreeView : public QTreeView
{
	Q_OBJECT

public:
	ListTreeView();
	~ListTreeView();

	void rebuildInfo();
	bool isChanged();

	void addOneCaptureItem(QString strNum, QString strTime, QString strSIP, 
								QString strDIP, QString strProto, QString strLength);

	void getOrderNumber(QModelIndex &index, QString &strNumber);

private:
	QStandardItemModel *mainModel;
	int iPosition;
};

#endif // LISTTREEVIEW_H_
