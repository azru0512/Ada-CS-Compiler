/** \page autotools Autotools
 *
 * 稍微了解 Makefile 有助於後續工作。請見 <a href="http://tetralet.luna.com.tw/index.php?op=ViewArticle&articleId=185">Makefile 語法簡介</a>。
 *
 * 本計劃採用 Autotools 來自動產生 Makefile。請見 <a href="http://tetralet.luna.com.tw/index.php?op=ViewArticle&articleId=200&blogId=1">利用 Autotools 來建立 Makefile 檔案</a>。
 *
 * 執行根目錄底下 autogen.sh 會依序呼叫 libtoolize aclocal autoconf automake 產生 Makefile 和 configure。
 *
 * 參考文件:
 *
 * <a href="http://sourceware.org/autobook/">GNU AUTOCONF AUTOMAKE, AND LIBTOOL</a>
 *
 */
