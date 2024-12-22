# PBL2: Ứng dụng quản lý đặt lịch khám bệnh

Dự án này là một ứng dụng quản lý đặt lịch khám bệnh, được phát triển trong khuôn khổ môn học **PBL2**. 
Ứng dụng giúp quản lý thông tin bệnh nhân, lịch khám và hỗ trợ các chức năng liên quan đến việc đặt lịch khám bệnh hiệu quả.

---

## Mục lục
1. [Giới thiệu](#giới-thiệu)
2. [Chức năng chính](#chức-năng-chính)
3. [Yêu cầu hệ thống](#yêu-cầu-hệ-thống)

---

## Giới thiệu
Ứng dụng này được thiết kế để:
- Hỗ trợ quản lý lịch khám bệnh của bệnh nhân và bác sĩ.
- Giảm thời gian xử lý thủ tục hành chính tại các cơ sở y tế.
- Cung cấp giao diện thân thiện với người dùng.

**Mục tiêu chính**:
- Quản lý thông tin bệnh nhân và bác sĩ.
- Sắp xếp lịch khám tự động.
- Cải thiện hiệu suất và giảm lỗi trong quản lý thủ công.

---

## Chức năng chính
1. **Quản lý tài khoản**:
   - Đăng ký, đăng nhập cho bệnh nhân và bác sĩ.
   - Phân quyền: quản trị viên, bác sĩ, bệnh nhân.
2. **Đặt lịch khám bệnh**:
   - Bệnh nhân chọn ngày, giờ và bác sĩ.
3. **Quản lý thông tin**:
   - Thông tin cá nhân của bệnh nhân và bác sĩ.
   - Lịch sử khám bệnh.
4. **Thông báo và nhắc nhở**:
   - Gửi thông báo nhắc lịch khám qua email/SMS (nếu có).
5. **Báo cáo**:
   - Thống kê số lượt khám, lịch hẹn trong ngày/tuần/tháng.

---

## Yêu cầu hệ thống
- **Ngôn ngữ lập trình**: C++
- **Phần mềm hỗ trợ**: Visual Studio Code
- **Cơ sở dữ liệu**: SQL Server (chạy trên Docker)
- **Hệ điều hành**: MacOS hoặc Windows
