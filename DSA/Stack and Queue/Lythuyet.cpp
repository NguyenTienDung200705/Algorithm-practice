/*
I. Ngăn xếp (Stack)
1. Khái niệm
    - Ngăn xếp là một kiểu danh sách mà việc bổ sung một phần tử và xóa một phần tử được thực hiện ở cuối danh sách.

    - Hãy hình dung ngăn xếp giống như một chồng đĩa. Các bạn muốn thêm một chiếc đĩa vào thì phải đặt nó lên đỉnh
  của chồng đĩa (phía cuối), và muốn lấy một chiếc đĩa ra thì cũng phải lấy từ trên xuống.

    - Phần tử ở đỉnh ngăn xếp (cuối danh sách) được gọi là phần tử top của ngăn xếp. Nguyên tắc thêm - xóa
      phần tử như trên được gọi là "vào sau ra trước", do đó ngăn xếp còn có tên gọi khác là danh sách kiểu LIFO
      (Last In First Out). Có 6 thao tác cơ bản ngăn xếp cung cấp:
        + init : Khởi tạo ngắn xếp rỗng
        + is_empty : Kiểm tra xem ngăn xếp có rỗng không.
        + is_full : Kiểm tra xem ngăn xếp có bị đầy (tràn) hay không.
        + get_top : Trả về phần tử ở đỉnh ngăn xếp.
        + push : Thêm một phần tử vào ngăn xếp.
        + pop : Lấy ra phần tử ở đỉnh ngăn xếp.

2. Biểu diễn ngăn xếp mảng
    - Để biểu diễn ngăn xếp, ta sử dụng một mảng elements để lưu các phần tử của ngăn xếp, phần tử cuối cùng của mảng
      chính là phần tử top của ngăn xếp. Containers vector trong C++ và list trong Python dễ dàng kiểm soát điều này.
*/
// Minh họa
/*
#include <bits/stdc++.h>
#include <vector>

using namespace std;

// Tạo một cấu trúc ngăn xếp là một vector có kiểu phần tử type.
typedef vector < {type} > stack_type;

// Khởi tạo ngăn xếp rỗng.
void create_stack(stack_type &st)
{
    st.resize(0);    
}

// Kiểm tra ngăn xếp có rỗng không.
bool is_empty(stack_type &st)
{
    return st.empty();
}

// Trả ra phần tử ở đỉnh ngăn xếp nếu tồn tại.
{type} get_top(stack_type &st)
{
    if (!st.empty())
        return st.elements.back();
    else
        {Báo_lỗi_ngăn_xếp_rỗng};
}

// Đẩy một phần tử vào ngăn xếp.
void push(stack_type &st, {type} x)
{
    stack.push_back(x);
}

// Lấy ra phần tử ở đỉnh ngăn xếp.
void pop(stack_type &st)
{
    return st.pop_back();
}
*/

/*
II Hàng đợi (Queue)
1. Khái niệm
    - Giống như tên gọi của mình, hàng đợi là một cấu trúc dữ liệu biểu diễn một danh sách các phần tử đứng trong "hàng chờ"
      được xử lý. Trong cấu trúc dữ liệu này, việc bổ sung một phần tử được thực hiện ở cuối danh sách, còn việc loại bỏ 
      một phần tử được thực hiện ở đầu danh sách.

    - Có thể tưởng tượng hàng đợi giống như một hàng người xếp hàng chờ mua vé, ai đến trước được mua trước và rời khỏi hàng,
      còn những người đến sau sẽ bổ sung vào cuối hàng. Vì nguyên tắc "vào trước ra trước" như vậy nên hàng đợi còn được
      gọi là danh sách kiểu FIFO (First In First Out).

    - Phần tử ở đầu hàng đợi sẽ gọi là phần tử front, còn phần tử ở cuối hàng đợi gọi là phần tử rear.
     Tương tự như ngăn xếp, có 6 thao tác cơ bản trên hàng đợi:
        + init : Khởi tạo một hàng đợi rỗng.
        + is_empty : Kiểm tra hàng đợi có rỗng hay không.
        + is_full : Kiểm tra hàng đợi đã bị đầy chưa.
        + get_front : Trả về giá trị của phần tử ở đầu hàng đợi.
        + push : Đẩy một phần tử vào cuối hàng đợi.
        + pop : Loại bỏ một phần tử ở đầu hàng đợi.

2. Biểu diễn hàng đợi bằng mảng
    - Giống như ngăn xếp, ta sử dụng một mảng elements để lưu các phần tử của hàng đợi. Tuy nhiên,
      ta phải sử dụng thêm một biến front để kiểm soát vị trí của phần tử đầu tiên trong hàng đợi,
      còn phần tử cuối cùng thì vẫn là phần tử cuối của vector hoặc list. Tương tự như ngăn xếp,
      thao tác kiểm tra is_full cũng không cần thiết phải cài đặt.
    
    - Ý tưởng sẽ là, nếu như thêm một phần tử vào hàng đợi thì đẩy nó vào cuối danh sách elements,
      còn khi lấy ra một phần tử ở đầu hàng đợi thì ta tăng biến front thêm 1 đơn vị,
      như vậy coi như các phần tử từ vị trí 0 tới vị trí front−1 trên mảng là các phần tử đã bị loại đi.

    - Cả hai thành phần trên có thể gộp lại thành một cấu trúc queue_type trong C++, hoặc một
      class queue_type trong Python.
      */

/*
#include <iostream>
#include <vector>

using namespace std;

const int max_size = {Kích_thước_cực_đại};

struct queue_type
{
    vector < {type} > elements;
    int front;
}

// Khởi tạo hàng đợi.
void init(queue_type &qu)
{
    qu.elements.resize(0);
    front = -1;
}

// Kiểm tra hàng đợi có rỗng không.
bool is_empty(queue_type &qu)
{
    return qu.front > qu.elements.size();
}

// Trả về phần tử ở đầu hàng đợi.
{type} get_front(queue_type qu)
{
    if (is_empty(qu))
        {Báo_lỗi_hàng_đợi_rỗng};
    else 
        return qu.elements[qu.front];
}

// Thêm một phần tử vào hàng đợi.
void push(queue_type &qu, {type} x)
{
    qu.elements.push_back(x);
}

// Xóa phần tử ở đầu hàng đợi.
void pop(queue_type &qu)
{
    if (is_empty(qu))
        {Báo_lỗi_hàng_đợi_rỗng};
    else 
        ++qu.front;
}

*/