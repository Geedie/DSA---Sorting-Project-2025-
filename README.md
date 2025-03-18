# DSA---Sorting-Project-2025-
A project for school submission (HCMUS) 
Hướng dẫn biên dịch và chạy chương trình
1. Biên dịch chương trình
Chạy lệnh sau để biên dịch toàn bộ chương trình bằng g++:
g++ -o sort_program main.cpp sorting_algorithms.cpp input_generator.cpp -std=c++11
2. Chạy chương trình
2.1 Chế độ thực thi thuật toán sắp xếp
Chạy một thuật toán sắp xếp trên dữ liệu từ file:
./sort_program -a [Algorithm] [Input filename] [Output parameter(s)]
Ví dụ:
./sort_program -a radix-sort input.txt -both
Chạy thuật toán sắp xếp trên dữ liệu tự động sinh:
./sort_program -a [Algorithm] [Input size] [Input order] [Output parameter(s)]
Ví dụ:
./sort_program -a selection-sort 50000 -rand -time
Chạy thuật toán trên tất cả các dạng dữ liệu:
./sort_program -a [Algorithm] [Input size] [Output parameter(s)]
Ví dụ:
./sort_program -a quick-sort 70000 -comp
2.2 Chế độ so sánh hai thuật toán
Chạy hai thuật toán trên dữ liệu từ file:
./sort_program -c [Algorithm 1] [Algorithm 2] [Input filename]
Ví dụ:
./sort_program -c heap-sort merge-sort input.txt
Chạy hai thuật toán trên dữ liệu tự động sinh:
./sort_program -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]
Ví dụ:
./sort_program -c quick-sort merge-sort 100000 -nsorted
3. Kiểm tra kết quả
Sau khi chạy chương trình, có thể kiểm tra kết quả bằng script kiểm tra:
python check_results.py
Script này sẽ kiểm tra xem dữ liệu trong output.txt có được sắp xếp đúng không.
