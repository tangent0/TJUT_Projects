-- phpMyAdmin SQL Dump
-- version 4.0.5
-- http://www.phpmyadmin.net
--
-- 主机: localhost
-- 生成日期: 2013 年 12 月 11 日 19:02
-- 服务器版本: 5.5.20-log
-- PHP 版本: 5.3.5

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- 数据库: `database_course`
--

-- --------------------------------------------------------

--
-- 表的结构 `grade`
--

CREATE TABLE IF NOT EXISTS `grade` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `stuNum` char(8) NOT NULL DEFAULT '',
  `shuju` tinyint(4) NOT NULL DEFAULT '60',
  `math` tinyint(4) NOT NULL DEFAULT '60',
  `computer` tinyint(4) NOT NULL DEFAULT '60',
  `engish` tinyint(4) NOT NULL DEFAULT '60',
  `db` tinyint(4) NOT NULL DEFAULT '60',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=4 ;

--
-- 转存表中的数据 `grade`
--

INSERT INTO `grade` (`id`, `stuNum`, `shuju`, `math`, `computer`, `engish`, `db`) VALUES
(1, '20106191', 88, 77, 89, 98, 77),
(2, '200000', 66, 66, 55, 67, 88),
(3, '2010611', 44, 55, 55, 44, 33);

-- --------------------------------------------------------

--
-- 表的结构 `student`
--

CREATE TABLE IF NOT EXISTS `student` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(4) NOT NULL DEFAULT '',
  `stuNum` char(8) NOT NULL DEFAULT '',
  `age` char(32) DEFAULT NULL,
  `sex` char(4) DEFAULT NULL,
  `phone` varchar(11) NOT NULL DEFAULT '',
  `email` char(64) NOT NULL DEFAULT '',
  `address` char(128) NOT NULL DEFAULT '',
  `major` char(128) NOT NULL DEFAULT '',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=6 ;

--
-- 转存表中的数据 `student`
--

INSERT INTO `student` (`id`, `name`, `stuNum`, `age`, `sex`, `phone`, `email`, `address`, `major`) VALUES
(3, '张飞', '200000', '1991-09-10', '男', '0228235558', '844444@qq.com', '红旗南路', '计院'),
(5, '李四', '11111', '1991-08-09', '男', '110111', '8233332450@qq.com', '河西区广东路店', '计算机');

-- --------------------------------------------------------

--
-- 表的结构 `user`
--

CREATE TABLE IF NOT EXISTS `user` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `username` char(24) NOT NULL DEFAULT '',
  `password` char(64) NOT NULL DEFAULT '',
  `email` char(64) NOT NULL DEFAULT '',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=4 ;

--
-- 转存表中的数据 `user`
--

INSERT INTO `user` (`id`, `username`, `password`, `email`) VALUES
(1, 'admin', '11111', '823542450@qq.com'),
(2, 'joey', '111', '844444@qq.com'),
(3, 'zhu', '111', '823542450@qq.com');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
