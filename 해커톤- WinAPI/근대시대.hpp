

void �ٴ�ô�(EventManager& evt_mng)
{
	{
		EventMaker e("�ѱ�����",  EventPriority::Normal);

		e->content =
			"���ѹα� ���ΰ� �������� 2�⵵ �ȵ� ����,\n\
���� ������ ������ ���ѹα����� \n\
1952�� 6�� 25�� ������ ������ ħ���Ͽ����ϴ�.\n\
�� �������μ� �β����⵵ �ϰ�, �����⵵ ������ \n\
���� ���� ��ħ�� ���� �� �Ѵٸ� \n\
������ �츮 ���並 �� �� �������� �ֽ��ϴ�.\n\
�츮�� �̸� �������� ��å�� ������ �մϴ�.";

		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�ô�"] != "�ٴ�ô�") return false;
			if (data.dict["�ѱ�����"] == "")
			{
				data.dict["�ѱ�����"] = "���۵�";
				return true;
			}
			else
				return false;
		};

		{
			EventSelectItemMaker s(e, "��� ���縦 �������� �����ô�!");
			s->content =
"������� �������� �����ϴ�.\n\
�ڱ�-3";
			s->CanRun = [&](Gamedata& data) {
				return data.player.res.money >= 3;
			};

			s->Effect = [&](Gamedata& data) {
				data.dict["�ѱ�����"] = "������ ��ġ";
				data.player.res.money -= 3;
			};
		}
		{
			EventSelectItemMaker s(e, "���縦 ������ ��ġ�ؾ� �������Դϴ�!");
			s->content =
"���� ���������� ��ġ�մϴ�.\n\
�ڱ�-1\n\
�ķ�-2";
			s->CanRun = [&](Gamedata& data) {
				return (data.player.res.money >= 1 && data.player.res.food >= 2);
			};

			s->Effect = [&](Gamedata& data) {
				data.dict["�ѱ�����"] = "���ﵹ��";
				data.player.res.money -= 1;
				data.player.res.food -= 2;
			};
		}
		{
			EventSelectItemMaker s(e, "�� �����ε��� ��� �԰� �ִµ� �츮�� �� �ѵ� �ٲ�ڽ��ϱ�?");
			s->content =
				"�޹��ϰ� ���� �غ� �ϰ� �Ǿ� \n\
�θ� ���ذ� ������ �� �Դϴ�.\n\
���� -2\n\
�η� -4\n\
[������ ��ħ�� �������� �츮���� �� �����ε��� �������� \n\
�屳Ŭ���� �𿩼� ��� �Ծ��ٰ� �Ѵ�.\n\
�Դٰ� ���� ����� ���� ������ ��κ��� �ܹ�, �ƴϸ� �ް����ٰ� �Ѵ�.]";
			s->Effect = [&](Gamedata& data) {
				data.dict["�ѱ�����"] = "���ﵹ��";
				data.player.res.milli -= 2;
				data.player.res.human -= 4;
			};
		}
	}

	//������ ����(�ݰ�)
	{
		EventMaker e("������ ����(�ݰ�)", EventPriority::Normal);

		e->content =
			"���ѱ��� 38���� �Ѿ� �츮�� ���並 ���� �����ϰ� �ֽ��ϴ�.\n\
���ѹα��� ���ѱ��� ���� ��� ��ġ�� �ؾ� �� ���Դϴ�.\n\
���̻��� ������ ������, �Ǵ�  ������ ���信 ���� �� �Ұ�����.\n\
";

		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�ô�"] != "�ٴ�ô�") return false;
			if (data.dict["�ѱ�����"] == "������ ��ġ")
			{
				data.dict["�ѱ�����"] = "���ﵹ��";
				return true;
			}
			else
				return false;
		};

		{
			EventSelectItemMaker s(e, "�����濡 �ִ� ���鿡�� �Ͽ� ���� �ݰ��� ����մϴ�.");
			s->content =
				"�츮�� ���� �غ� �� �Ǿ�����, \n\
������ ��Ȳ�ϼ��� �� ���� ���� ���� �� ���� �ֽ��ϴ�.\n\
������ ���رԸ�� ���� ����Ҽ� �������Դϴ�.\n\
���� Ȯ���� �ݰ��� �����մϴ�.\n\
�ڱ�+2\n\
����-4\n\
�η�-3";
			s->CanRun = [&](Gamedata& data) {
				return data.player.res.milli >= 3 && data.player.res.human >= 1;
			};

			s->Effect = [&](Gamedata& data) {

				if (evt_mng.RandomPercent(20))
				{
					data.dict["�ѱ�����"] = "�¸�";
				}
				else
				{
					data.dict["�ѱ�����"] = "���ﵹ��";
				}

				data.player.res.money += 2;
				data.player.res.milli -= 4;
				data.player.res.human -= 3;
			};
		}
		{
			EventSelectItemMaker s(e, "�����濡 �ִ� ���鿡�� �Ͽ� ���� �� ����մϴ�.");
			s->content =
				"�츮 ���� ���� �غ��Ű��, \n\
�����濡�� �� �� �� �ֵ��� �մϴ�.\n\
������ ���� ���� Ȯ���� �� �Ը� �� �ֽ��ϴ�.\n\
�ڱ�-3\n\
����-1\n\
�η�-1";
			s->CanRun = [&](Gamedata& data) {
				return data.player.res.money >= 1;
			};

			s->Effect = [&](Gamedata& data) {

				if (evt_mng.RandomPercent(35))
				{
					data.dict["�ѱ�����"] = "�¸�";
				}
				else
				{
					data.dict["�ѱ�����"] = "���ﵹ��";
				}

				data.player.res.money -= 3;
				data.player.res.milli -= 1;
				data.player.res.human -= 1;
			};
		}
	}

	//���ﵹ��
	{
		EventMaker e("���ﵹ��", EventPriority::Normal);

		e->content =
			"�츮����� ���Ӿ��� �ĵ����� ������ ����� ���Ƴ��� �ֽ��ϴ�. \n\
������ �츮 �������δ� �� ������ ������ ����� ���Դϴ�.";

		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�ô�"] != "�ٴ�ô�") return false;
			return data.dict["�ѱ�����"] == "���ﵹ��";
		};

		{
			EventSelectItemMaker s(e, "�̱��� ������ ��û�մϴ�.");
			s->content =
				"�̱��� ������ ��û�Ͽ� �¸��� Ȯ���� ���δ�.\n\
����+4\n\
�ܱ�-2\n\
��-2";
			s->CanRun = [&](Gamedata& data) {
				return 
					data.player.res.human >= 3 &&
					data.player.res.diplo >= 2 &&
					data.player.res.money >= 2;
			};

			s->Effect = [&](Gamedata& data) {
				data.dict["�ѱ�����"] = "�¸�";
				data.player.res.milli += 4;
				data.player.res.diplo -= 2;
				data.player.res.money -= 2;
			};
		}
		{
			EventSelectItemMaker s(e, "������ ���� �ʿ� ���� �츮 �������� ����մϴ�.");
			s->content = "������û�� ���� �ʽ��ϴ�.\n\
���� Ȯ���� ���￡�� �й��մϴ�.";

			s->Effect = [&](Gamedata& data) {
				if (evt_mng.RandomPercent(70))
				{
					data.dict["�ѱ�����"] = "�й�";
				}
				else
				{
					data.dict["�ѱ�����"] = "�¸�";
				}
			};
		}
	}	
} 