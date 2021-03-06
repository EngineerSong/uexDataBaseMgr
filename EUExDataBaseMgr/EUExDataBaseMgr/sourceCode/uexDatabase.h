/**
 *
 *	@file   	: uexDatabase.h  in EUExDataBaseMgr
 *
 *	@author 	: CeriNo
 * 
 *	@date   	: 16/8/1
 *
 *	@copyright 	: 2016 The AppCan Open Source Project.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger,uexDatabaseTransactionResult){
    uexDatabaseTransactionSuccess = 0,
    uexDatabaseTransactionRollback,
    uexDatabaseTransactionError,
};

@interface uexDatabase: NSObject
@property(nonatomic,retain,class) NSString *dbFolderPath;
- (BOOL)open:(NSString *)dbName;
- (BOOL)close;
- (void)execSQL:(NSString *)SQL completion:(void (^)(BOOL isSuccess))completion;
- (void)selectSQL:(NSString *)SQL completion:(void (^)(NSArray<NSDictionary *>* result))completion;


- (void)doTransactionWithSQLs:(NSArray<NSString *> *)sqls completion:(void (^)(uexDatabaseTransactionResult result))completion;


/**
 *  @note parameter: jsFunc 此JSFunction中应该有执行SQL语句的动作
 */
- (void)doTransaction:(ACJSFunctionRef *)jsFunc completion:(void (^)(uexDatabaseTransactionResult result))completion;

@end
