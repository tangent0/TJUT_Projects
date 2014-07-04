-- phpMyAdmin SQL Dump
-- version 4.0.5
-- http://www.phpmyadmin.net
--
-- 主机: localhost
-- 生成日期: 2013 年 12 月 29 日 18:27
-- 服务器版本: 5.5.20-log
-- PHP 版本: 5.3.5

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- 数据库: `waijiao`
--

-- --------------------------------------------------------

--
-- 表的结构 `messages`
--

CREATE TABLE IF NOT EXISTS `messages` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `sender` varchar(64) NOT NULL,
  `getter` varchar(64) NOT NULL,
  `content` varchar(3600) NOT NULL,
  `sendTime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `isGet` tinyint(4) DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=4 ;

--
-- 转存表中的数据 `messages`
--

INSERT INTO `messages` (`id`, `sender`, `getter`, `content`, `sendTime`, `isGet`) VALUES
(1, 'Monica', 'Joey', 'hello ,Joey', '2013-12-28 13:08:58', 0),
(2, 'joey', 'Monica', 'hi Monica', '2013-12-28 13:09:23', 0),
(3, 'Monica', 'Joey', 'how are you?', '2013-12-28 13:12:30', 0);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
