-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Czas generowania: 14 Lut 2023, 21:16
-- Wersja serwera: 10.4.27-MariaDB
-- Wersja PHP: 8.0.25

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Baza danych: `pociagi_v1`
--

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `pociag`
--

CREATE TABLE `pociag` (
  `Id_poc` int(11) NOT NULL,
  `Nazwa_poc` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Zrzut danych tabeli `pociag`
--

INSERT INTO `pociag` (`Id_poc`, `Nazwa_poc`) VALUES
(1, 'SIZD');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `stacje`
--

CREATE TABLE `stacje` (
  `Id_przy` int(11) NOT NULL,
  `Nazwa_stacji` varchar(20) NOT NULL,
  `Poz_x` int(11) NOT NULL,
  `Poz_y` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Zrzut danych tabeli `stacje`
--

INSERT INTO `stacje` (`Id_przy`, `Nazwa_stacji`, `Poz_x`, `Poz_y`) VALUES
(1, 'Wrocław', 45, 75),
(2, 'Legnica', 19, 86),
(3, 'Głogów', 11, 35),
(4, 'Lubin', 17, 23),
(5, 'Jelenia Góra', 65, 33),
(6, 'Świdnica', 42, 21),
(7, 'Góra', 9, 76),
(8, 'Zgorzelec', 74, 28),
(9, 'Bolesławiec', 40, 10),
(10, 'Oława', 53, 47),
(11, 'Bydgoszcz', 22, 52),
(12, 'Toruń', 37, 63),
(13, 'Włocławek', 53, 29),
(14, 'Grudziądz', 11, 84),
(15, 'Inowrocław', 32, 49),
(16, 'Brodnica', 60, 8),
(17, 'Świecie', 78, 11),
(18, 'Nakło nad Notecią', 19, 43),
(19, 'Chełmno', 75, 16),
(20, 'Tuchola', 91, 7),
(21, 'Lublin', 49, 29),
(22, 'Chełm', 75, 82),
(23, 'Zamość', 82, 44),
(24, 'Biała Podlaska', 8, 58),
(25, 'Świdnik', 43, 40),
(26, 'Puławy', 57, 55),
(27, 'Kraśnik', 22, 90),
(28, 'Świdnik', 39, 80),
(29, 'Janów Lubelski', 65, 93),
(30, 'Łęczna', 13, 75),
(31, 'Łódź', 46, 81),
(32, 'Piotrków Trybunalski', 87, 16),
(33, 'Tomaszów Mazowiecki', 7, 53),
(34, 'Bełchatów', 32, 47),
(35, 'Zgierz', 67, 42),
(36, 'Radomsko', 95, 72),
(37, 'Skierniewice', 50, 39),
(38, 'Kutno', 11, 27),
(39, 'Łowicz', 17, 58),
(40, 'Pabianice', 79, 21),
(41, 'Kraków', 29, 41),
(42, 'Tarnów', 75, 84),
(43, 'Nowy Sącz', 95, 29),
(44, 'Chrzanów', 62, 57),
(45, 'Oświęcim', 45, 90),
(46, 'Wieliczka', 10, 27),
(47, 'Skawina', 37, 12),
(48, 'Bochnia', 80, 58),
(49, 'Brzesko', 7, 95),
(50, 'Zakopane', 69, 17),
(51, 'Warszawa', 56, 48),
(52, 'Radom', 85, 20),
(53, 'Płock', 33, 90),
(54, 'Siedlce', 78, 51),
(55, 'Ostrołęka', 12, 76),
(56, 'Legionowo', 61, 16),
(57, 'Piaseczno', 46, 33),
(58, 'Pruszków', 70, 64),
(59, 'Otwock', 17, 58),
(60, 'Grodzisk Mazowiecki', 38, 81),
(61, 'Opole', 50, 50),
(62, 'Kędzierzyn-Koźle', 85, 15),
(63, 'Brzeg', 70, 75),
(64, 'Prudnik', 15, 45),
(65, 'Kluczbork', 40, 10),
(66, 'Nysa', 30, 80),
(67, 'Głubczyce', 20, 20),
(68, 'Strzelce Opolskie', 75, 70),
(69, 'Krapkowice', 60, 35),
(70, 'Olesno', 5, 65),
(71, 'Rzeszów', 35, 35),
(72, 'Przemyśl', 85, 10),
(73, 'Stalowa Wola', 45, 65),
(74, 'Mielec', 20, 40),
(75, 'Tarnobrzeg', 75, 80),
(76, 'Krosno', 5, 55),
(77, 'Jasło', 70, 15),
(78, 'Dębica', 25, 85),
(79, 'Sanok', 60, 40),
(80, 'Łańcut', 50, 75),
(81, 'Białystok', 12, 73),
(82, 'Łomża', 28, 61),
(83, 'Suwałki', 2, 56),
(84, 'Augustów', 3, 35),
(85, 'Bielsk Podlaski', 27, 89),
(86, 'Zambrów', 21, 50),
(87, 'Mońki', 8, 15),
(88, 'Hajnówka', 38, 63),
(89, 'Siemiatycze', 22, 84),
(90, 'Wysokie Mazowieckie', 44, 75),
(91, 'Gdańsk', 20, 60),
(92, 'Gdynia', 30, 60),
(93, 'Tczew', 18, 55),
(94, 'Wejherowo', 25, 55),
(95, 'Sopot', 32, 62),
(96, 'Rumia', 28, 57),
(97, 'Reda', 24, 58),
(98, 'Kartuzy', 18, 65),
(99, 'Puck', 33, 58),
(100, 'Starogard Gdański', 15, 57),
(101, 'Katowice', 10, 20),
(102, 'Czestochowa', 15, 25),
(103, 'Sosnowiec', 5, 15),
(104, 'Gliwice', 25, 10),
(105, 'Zabrze', 12, 17),
(106, 'Bytom', 8, 18),
(107, 'Bielsko-Biala', 30, 10),
(108, 'Ruda Slaska', 11, 22),
(109, 'Rybnik', 20, 5),
(110, 'Tychy', 10, 15),
(111, 'Kielce', 10, 50),
(112, 'Ostrowiec Świętokrzyski', 20, 41),
(113, 'Starachowice', 30, 70),
(114, 'Sandomierz', 60, 30),
(115, 'Skarżysko-Kamienna', 50, 60),
(116, 'Końskie', 80, 20),
(117, 'Staszów', 70, 50),
(118, 'Pińczów', 40, 10),
(119, 'Jędrzejów', 90, 70),
(120, 'Busko-Zdrój', 80, 50),
(121, 'Olsztyn', 23, 42),
(122, 'Elbląg', 13, 88),
(123, 'Ełk', 35, 29),
(124, 'Giżycko', 62, 12),
(125, 'Iława', 4, 73),
(126, 'Bartoszyce', 49, 87),
(127, 'Braniewo', 8, 33),
(128, 'Kętrzyn', 60, 57),
(129, 'Lidzbark Warmiński', 72, 18),
(130, 'Działdowo', 80, 52),
(131, 'Poznań', 25, 50),
(132, 'Kalisz', 60, 30),
(133, 'Konin', 80, 50),
(134, 'Piła', 20, 15),
(135, 'Ostrów Wielkopolski', 40, 75),
(136, 'Gniezno', 30, 40),
(137, 'Śrem', 55, 80),
(138, 'Września', 80, 20),
(139, 'Kościan', 10, 90),
(140, 'Wągrowiec', 50, 10),
(141, 'Szczecin', 20, 30),
(142, 'Koszalin', 45, 60),
(143, 'Stargard', 30, 20),
(144, 'Świnoujście', 60, 80),
(145, 'Kołobrzeg', 70, 50),
(146, 'Police', 25, 40),
(147, 'Gryfino', 10, 90),
(148, 'Goleniów', 40, 10),
(149, 'Świdwin', 50, 70),
(150, 'Gryfice', 80, 30);
----------------------------------------------------------
--
-- Struktura tabeli dla tabeli `trasa`
--

CREATE TABLE `trasa` (
  `Id_poc` int(11) NOT NULL,
  `Id_przy` int(11) NOT NULL,
  `Id_trasy` int(11) NOT NULL,
  `Nr_przystanku` int(11) NOT NULL,
  `Godzina_odjazdu` time NOT NULL,
  `Godzina_przyjazdu` time NOT NULL,
  `Data` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Zrzut danych tabeli `trasa`
--

INSERT INTO `trasa` (`Id_poc`, `Id_przy`, `Id_trasy`, `Nr_przystanku`, `Godzina_odjazdu`, `Godzina_przyjazdu`, `Data`) VALUES
(1, 1, 1, 1, '07:05:00', '07:00:00', '2023-02-01'),
(1, 2, 1, 2, '07:21:00', '07:20:00', '2023-02-01'),
(1, 2, 1, 3, '07:45:00', '07:44:00', '2023-02-01'),
(1, 3, 1, 4, '08:00:00', '08:01:00', '2023-02-01'),
(1, 1, 1, 5, '00:00:00', '08:01:00', '2023-02-01');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `trasy`
--

CREATE TABLE `trasy` (
  `Id_poc` int(11) NOT NULL,
  `Ilosc_przy` int(11) NOT NULL,
  `Stacja_pocz` varchar(20) NOT NULL,
  `Stacja_Kon` varchar(20) NOT NULL,
  `Id_trasy` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Zrzut danych tabeli `trasy`
--

INSERT INTO `trasy` (`Id_poc`, `Ilosc_przy`, `Stacja_pocz`, `Stacja_Kon`, `Id_trasy`) VALUES
(1, 5, 'Sieradz', 'Zduńska Wola', 1);

--
-- Indeksy dla zrzutów tabel
--

--
-- Indeksy dla tabeli `pociag`
--
ALTER TABLE `pociag`
  ADD PRIMARY KEY (`Id_poc`),
  ADD KEY `Id_poc` (`Id_poc`);

--
-- Indeksy dla tabeli `stacje`
--
ALTER TABLE `stacje`
  ADD PRIMARY KEY (`Id_przy`),
  ADD KEY `Id_przy` (`Id_przy`),
  ADD KEY `Nazwa_stacji` (`Nazwa_stacji`);

--
-- Indeksy dla tabeli `trasa`
--
ALTER TABLE `trasa`
  ADD KEY `Id_poc` (`Id_poc`),
  ADD KEY `Id_przy` (`Id_przy`),
  ADD KEY `Id_trasy` (`Id_trasy`);

--
-- Indeksy dla tabeli `trasy`
--
ALTER TABLE `trasy`
  ADD PRIMARY KEY (`Id_trasy`),
  ADD KEY `Id_trasy` (`Id_trasy`),
  ADD KEY `Id_poc` (`Id_poc`),
  ADD KEY `Ilosc_przy` (`Ilosc_przy`),
  ADD KEY `Stacja_pocz` (`Stacja_pocz`),
  ADD KEY `Stacja_Kon` (`Stacja_Kon`);

--
-- AUTO_INCREMENT dla zrzuconych tabel
--

--
-- AUTO_INCREMENT dla tabeli `pociag`
--
ALTER TABLE `pociag`
  MODIFY `Id_poc` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- Ograniczenia dla zrzutów tabel
--

--
-- Ograniczenia dla tabeli `trasa`
--
ALTER TABLE `trasa`
  ADD CONSTRAINT `trasa_ibfk_1` FOREIGN KEY (`Id_przy`) REFERENCES `stacje` (`Id_przy`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `trasa_ibfk_2` FOREIGN KEY (`Id_poc`) REFERENCES `pociag` (`Id_poc`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `trasa_ibfk_3` FOREIGN KEY (`Id_trasy`) REFERENCES `trasy` (`Id_trasy`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Ograniczenia dla tabeli `trasy`
--
ALTER TABLE `trasy`
  ADD CONSTRAINT `trasy_ibfk_1` FOREIGN KEY (`Id_poc`) REFERENCES `pociag` (`Id_poc`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `trasy_ibfk_2` FOREIGN KEY (`Stacja_pocz`) REFERENCES `stacje` (`Nazwa_stacji`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `trasy_ibfk_3` FOREIGN KEY (`Stacja_Kon`) REFERENCES `stacje` (`Nazwa_stacji`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
