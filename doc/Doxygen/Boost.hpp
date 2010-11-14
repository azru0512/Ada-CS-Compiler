/** \page boost Boost
 *
 * 本計劃使用到的 Boost 函式庫:
 * - <a href="http://www.boost.org/doc/libs/release/doc/html/foreach.html">Foreach</a>
 * - <a href="http://www.boost.org/doc/libs/release/libs/conversion/lexical_cast.htm">Lexical Cast</a>
 * - <a href="http://www.boost.org/doc/libs/1_44_0/libs/ptr_container/doc/ptr_container.html">Pointer Container</a>
 * - <a href="http://www.boost.org/doc/libs/release/doc/html/program_options.html">Program Options</a>
 * - <a href="http://www.boost.org/doc/libs/1_44_0/doc/html/ref.html">Ref</a>  
 * - <a href="http://www.boost.org/doc/libs/release/libs/smart_ptr/smart_ptr.htm">Smart Pointers</a>
 * - <a href="http://www.boost.org/doc/libs/release/doc/html/string_algo.html">String Algo</a>  
 *
 * Ref
 * -<a href="http://stackoverflow.com/questions/2561145/difference-between-boostref-and-regular-references">Difference between boost::ref and regular references</a>
 *
 * 智能指針 (Smart Pointers)
 * - <a href="http://www.informit.com/guides/content.aspx?g=cplusplus&seqNum=158">Using auto_ptr To Automate Memory Management</a>
 * - <a href="http://www.informit.com/guides/content.aspx?g=cplusplus&seqNum=400">Using unique_ptr, Part I</a>  
 * - <a href="http://www.informit.com/guides/content.aspx?g=cplusplus&seqNum=401">Using unique_ptr, Part II</a>
 * - <a href="http://www.informit.com/guides/content.aspx?g=cplusplus&seqNum=239">The shared_ptr Class</a>
 * - <a href="http://www.informit.com/guides/content.aspx?g=cplusplus&seqNum=240">The shared_ptr Class, II</a>
 * - <a href="http://www.codeproject.com/KB/stl/boostsmartptr.aspx">Smart Pointers to boost your code</a>
 * 
 * Smart Pointers FAQ:
 * - Q: 裸指針為什麼不能當作實參數傳給一接收 shared_ptr 參數的函式。見 http://codepad.org/rJq5VEIJ。
 * - A: shared_ptr 並不提供此種型別轉換。請用 boost::make_shared<T> (args)。見 http://codepad.org/3cbMA2I3。
 *
 * 參考文件:
 * - <a href="http://catphive.net/blog/?p=226">shared_ptr and make_shared(args)</a>
 * - <a href="http://stackoverflow.com/questions/1373896/boost-make-shared-takes-in-a-const-reference-any-way-to-get-around-this">boost make_shared takes in a const reference. Any way to get around this?</a>  
 *
 * 指針容器 (Pointer Container)
 * - <a href="http://www.drdobbs.com/cpp/184406287">Pointer Containers</a>
 * - <a href="http://foxyang.blogspot.com/2007/06/boost-pointer-container.html">Boost Pointer Container</a>  
 *
 * 參考文件:
 * - <a href="http://jvm.cs.nctu.edu.tw/~chenwj/ebook/Beyond_STL_cn.chm">Beyond STL</a>
 * - <a href="http://jvm.cs.nctu.edu.tw/~chenwj/ebook/boost_doc/doc/html">boost 文档</a>  
 *
 * 外部連結:
 * - <a href="http://www.boost.org/">Boost</a>
 * - <a href="http://code.google.com/p/boost-doc-zh/">汉化 boost 文档</a>    
 * - <a href="http://boost.ez2learn.com/">汉化 boost 文档 - 繁體</a>
 */ 
